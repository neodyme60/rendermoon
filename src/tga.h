#include <fstream>
#include <iostream>

class TGA
{
public:
    unsigned int m_Width, m_Height, m_BitsPerPixel, m_Size;
    char *m_Data;
    char m_Header[18];
    bool ImageCompressed;

    TGA()
    {

    }

    ~TGA()
    {
        if (data)
            free(m_Data);
    }

    bool load(const std::string& filename)
    {
        short BitsPerPixel = 0;
        std::fstream hFile(FilePath, std::ios::in | std::ios::binary);
        if (!hFile.is_open()){throw std::invalid_argument("File Not Found.");}

        m_Header[18] = {0};
        unsigned char DeCompressed[12] = {0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
        unsigned char IsCompressed[12] = {0x0, 0x0, 0xA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

        hFile.read(reinterpret_cast<char*>(&m_Header), sizeof(m_Header));

        if (!memcpy(DeCompressed, &m_Header, sizeof(DeCompressed)))
        {
            m_BitsPerPixel = m_Header[16];
            m_Width  = m_Header[13] * 0xFF + m_Header[12];
            m_Height = m_Header[15] * 0xFF + m_Header[14];
            m_Size  = ((width * m_BitsPerPixel + 31) / 32) * 4 * m_Height;

            if ((m_BitsPerPixel != 24) && (m_BitsPerPixel != 32))
            {
                hFile.close();
//                throw std::invalid_argument("Invalid File Format. Required: 24 or 32 Bit Image.");
                return false;
            }

            m_Data = (char*)malloc(m_Size);
            ImageCompressed = false;
            hFile.read((char*)m_Data, m_Size);
        }
        else if (!memcpy(IsCompressed, &m_Header, sizeof(IsCompressed)))
        {
            m_BitsPerPixel = m_Header[16];
            m_Width  = m_Header[13] * 0xFF + m_Header[12];
            m_Height = m_Header[15] * 0xFF + m_Header[14];
            m_Size  = ((m_Width * BitsPerPixel + 31) / 32) * 4 * m_Height;

            if ((m_BitsPerPixel != 24) && (m_BitsPerPixel != 32))
            {
                hFile.close();
//                throw std::invalid_argument("Invalid File Format. Required: 24 or 32 Bit Image.");
                return false;
            }

            int CurrentByte = 0;
            std::size_t CurrentPixel = 0;
            ImageCompressed = true;
            unsigned char ChunkHeader = {0};
            int BytesPerPixel  = (m_BitsPerPixel / 8);
            m_Data = (char *)malloc(m_Size);

            do
            {
                hFile.read(reinterpret_cast<char*>(&ChunkHeader), sizeof(ChunkHeader));

                if(ChunkHeader < 128)
                {
                    ++ChunkHeader;
                    for(int I = 0; I < ChunkHeader; ++I, ++CurrentPixel)
                    {
                        char rgba[4];
                        hFile.read(&rgba[0], BytesPerPixel);

                        m_Data[CurrentByte++] = rgba[0];
                        m_Data[CurrentByte++] = rgba[1];
                        m_Data[CurrentByte++] = rgba[2];
                        if (m_BitsPerPixel  > 24)
                            m_Data[CurrentByte++] = rgba[3];
                    }
                }
                else
                {
                    ChunkHeader -= 127;
                    char rgba[4];
                    hFile.read(&rgba[0], BytesPerPixel);
                    for(int I = 0; I < ChunkHeader; ++I, ++CurrentPixel)
                    {
                        m_Data[CurrentByte++] = rgba[0];
                        m_Data[CurrentByte++] = rgba[1];
                        m_Data[CurrentByte++] = rgba[2];
                        if (m_BitsPerPixel > 24) m_Data[CurrentByte++] = rgba[3];
                    }
                }
            }
            while(CurrentPixel < (m_Width * m_Height));
        }
        else
        {
            hFile.close();
            return false;
 //           throw std::invalid_argument("Invalid File Format. Required: 24 or 32 Bit TGA File.");
        }

        hFile.close();
        return true;
    }

    bool save(const std::string& filename)
    {
        FILE *fp = fopen("out.tga", "w");
        if (fp == NULL)
            return false;

        m_Header[18] = {0}; // char = byte
        m_Header[2] = 2; // truecolor
        m_Header[12] = m_Width & 0xFF;
        m_Header[13] = (m_Width >> 8) & 0xFF;
        m_Header[14] = m_Height & 0xFF;
        m_Header[15] = (m_Height >> 8) & 0xFF;
        m_Header[16] = 24; // bits per pixel

        fwrite((const char *) &m_Header, 1, sizeof(m_Header), fp);

        // The image data is stored bottom-to-top, left-to-right
        for (int y = m_Height - 1; y >= 0; y--)
            for (int x = 0; x < m_Width; x++) {
                char b = (m_Data[x + (y * m_Width)] & 0x0000FF);
                char g = (m_Data[x + (y * m_Width)] & 0x00FF00) >> 8;
                char r = (m_Data[x + (y * m_Width)] & 0xFF0000) >> 16;
                putc((int) (b & 0xFF), fp);
                putc((int) (g & 0xFF), fp);
                putc((int) (r & 0xFF), fp);
            }

        // The file footer
        static const char footer[26] =
                "\0\0\0\0" // no extension area
                        "\0\0\0\0" // no developer directory
                        "TRUEVISION-XFILE" // yep, this is a TGA file
                        ".";
        fwrite((const char *) &footer, 1, sizeof(footer), fp);
        fclose(fp);
        return true;
    }
};
