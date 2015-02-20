#include <rendermoon.h>
#include <fstream>

ObjMeshLoader::ObjMeshLoader()
{

}

ObjMeshLoader::~ObjMeshLoader()
{

}


bool ObjMeshLoader::Parse(const std::string& strFileName)
{
    ifstream ifs(strFileName.c_str(), ios::in|ios::ate);
    if (!ifs)
        return false;

    //reset internal data
    m_VertexIndex.clear();
    m_Points.clear();
    m_uvs.clear();
    m_uvs_tmp.clear();
    m_Normals.clear();
    m_Normals_tmp.clear();

    const int fileSize = ifs.tellg();    //  get the file size (we started at the end)...
    ifs.seekg (0, ios::beg);  //  ...then get back to start

//        if (0 == fileSize)
//          throw CEmptyFileException();
    if (0 == fileSize)
        return false;

    //	explain what's going on
//    CLogger::get() << "Parsing file \"" << strFileName << "\" (file size = " << fileSize << " bytes)...\n" << flush;

    // do a bit of cleaning before adding data in case the mesh was used before.
//       pMesh->clear();

    // and go.
    int percent = 10;	//	progress indicator
    while(skipCommentLine(ifs))
    {
        // show progress for files larger than one Mo
        if ((fileSize > 1024*1024) && (100*ifs.tellg()/fileSize >= percent)) {
            percent = 100*ifs.tellg()/fileSize;
            percent = (percent/10)*10;
    //        CLogger::get() << "  " << percent << " % done...\n" << flush;
            percent += 10;
        }

        if (false == processLine(ifs))
            break;
    }

    ifs.close();
/*
    CLogger::get() << "File \""<< strFileName <<"\" fully parsed.\n";
    CLogger::get() << "  Total vertices: " << pMesh->getNumVertices() << ".\n";
    CLogger::get() << "  Total texture coords: " << pMesh->getNumTextureCoords() << ".\n";
    CLogger::get() << "  Total normals: " << pMesh->getNumNormals() << ".\n";
    CLogger::get() << "  Total faces: " << pMesh->getNumFaces() << ".\n";
    CLogger::get() << "Approximative mesh size: " << pMesh->getByteSize() << " bytes (reduced to " << flush;
    pMesh->shrinkToFit();
    CLogger::get() << pMesh->getByteSize() << " bytes).\n";
*/
    return true;
}

bool ObjMeshLoader::processLine(istream& is)
{
    string ele_id;
    float x, y, z;

    if (!(is >> ele_id))
        return false;

    if ("mtllib" == ele_id)
    {
        string strFileName;
        is >> strFileName;
//        parseMtlLib(strFileName);
    }
    else if ("usemtl" == ele_id)
    {
        string strMtlName;
        is >> strMtlName;
/*
        map<string, SMaterial>::iterator it = m_materialMap.find(strMtlName);
        if (it != m_materialMap.end())
            pMesh->setMaterial((*it).second);
        else
            CLogger::get() << "  * Material not found in current mtllib :\"" << strMtlName << "\". Ignoring material.\n";
*/
    }
    else if ("v" == ele_id) {	//	vertex data
        is >> x >> y >> z;
        m_Points.push_back(Point(x, y, z));
    }
    else if ("vt" == ele_id) {	// texture data
        is >> x >> y >> z;
        is.clear();                           // is z (i.e. w) is not available, have to clear error flag.
//        m_uvs.push_back(x);
//        m_uvs.push_back(y);
    }
    else if ("vn" == ele_id) {	// normal data
        is >> x >> y >> z;
        if(!is.good()) {                     // in case it is -1#IND00
            x = y = z = 0.0;
            is.clear();
            skipLine(is);
        }
        m_Normals_tmp.push_back(Normal(x, y, z));
    }
    else if ("f" == ele_id) {	//	face data
        //	face treatment
        //  Note: obviously this technique only works for convex polygons with ten verts or less.
        int vi[10];                               // vertex indices.
        int ni[10] = { -1, -1, -1, -1, };         // normal indices.
        int ti[10] = { -1, -1, -1, -1, };         // tex indices.
        int i = 0;
        for (char c; i<10; ++i)
        {
            if(m_uvs.size()==0 && m_Normals_tmp.size()==0)
                is >> vi[i];
            else if(m_uvs.size()==0)
                is >> vi[i] >> c >> c >> ni[i];
            else if(m_Normals_tmp.size()==0)
                is >> vi[i] >> c >> ti[i];
            else
                is >> vi[i] >> c >> ti[i] >> c >>  ni[i];

            if(!is.good())
                break;
        }
        for (int k=0; k < i-2; ++k)
        {
            m_VertexIndex.push_back(vi[0]-1);
            m_VertexIndex.push_back(vi[k+1]-1);
            m_VertexIndex.push_back(vi[k+2]-1);

            if (m_Normals_tmp.size()>0)
            {
                m_Normals.push_back(m_Normals_tmp[ni[0]-1]);
                m_Normals.push_back(m_Normals_tmp[ni[k+1]-1]);
                m_Normals.push_back(m_Normals_tmp[ni[k+2]-1]);
            }
        }

        is.clear();
    }
    else
        skipLine(is);
    return true;
}

void ObjMeshLoader::skipLine(istream& is)
{
    char next;
    is >> std::noskipws;
    while( (is >> next) && ('\n' != next) );
}

bool ObjMeshLoader::skipCommentLine(istream& is)
{
    char next;
    while( is >> std::skipws >> next )
    {
        is.putback(next);
        if ('#' == next)
            skipLine(is);
        else
            return true;
    }
    return false;
}

// the ".mtl" parsing logic is in the CMtlGrammar and CMtlActions classes (which use Boost's Spirit parser generator)
void ObjMeshLoader::parseMtlLib(const string& strFileName)
{
    //	render the ".mtl" file path application relative (instead of ".obj" file relative)
//    path filePath = m_branchPath/strFileName;
 //   CLogger::get() << "  Parsing mtllib \"" << strFileName << "\"...\n";
    //	Process...
 //   CMtlParser::parse(m_materialMap, filePath.string());

//    CLogger::get() << "  \"" << strFileName << "\" fully parsed.\n";
}
