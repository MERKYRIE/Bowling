#include"ElementBufferObject.hpp"

#include"Debug.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CElementBufferObject::CElementBufferObject(const std::vector<std::uint32_t>& PElements)
    {
        glGenBuffers(1 , &FIdentifier);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , FIdentifier);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , PElements.size() * sizeof(std::uint32_t) , PElements.data() , GL_STATIC_DRAW);
        GDebug.OOpenGraphicsLibraryError();
        FSize = PElements.size();
    }
    std::intmax_t CElementBufferObject::OSize() const
    {
        return FSize;
    }
    CElementBufferObject::~CElementBufferObject()
    {
        glDeleteBuffers(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}