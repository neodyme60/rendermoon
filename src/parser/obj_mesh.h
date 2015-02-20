#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_PARSER_OBJMESH__
#define __RENDERMOON_PARSER_OBJMESH__


class ObjMeshLoader
{
public:
    ObjMeshLoader();
    virtual ~ObjMeshLoader();

    bool Parse(const std::string&);
    bool processLine(istream&);
    void skipLine(istream&);
    bool skipCommentLine(istream&);
    void parseMtlLib(const string&);


    std::vector<int>    m_VertexIndex;
    std::vector<Point>  m_Points;
    std::vector<float>  m_uvs;
    std::vector<Normal> m_Normals;
    std::vector<float>  m_uvs_tmp;
    std::vector<Normal> m_Normals_tmp;
};
#endif

