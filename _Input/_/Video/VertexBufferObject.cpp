#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CVertexBufferObject::CVertexBufferObject(const std::vector<std::array<float , 5>>& PVertices)
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , FIdentifier);
        glBufferData(GL_ARRAY_BUFFER , PVertices.size() * sizeof(std::array<float , 5>) , PVertices.data() , GL_STATIC_DRAW);
        GDebug.OOpenGraphicsLibraryError();
        FSize = PVertices.size();
    }
    std::intmax_t CVertexBufferObject::OSize() const
    {
        return FSize;
    }
    CVertexBufferObject::~CVertexBufferObject()
    {
        glDeleteBuffers(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}