#include"VertexArrayObject.hpp"

#include"ElementBufferObject.hpp"
#include"VertexBufferObject.hpp"

#include"Debug.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CVertexArrayObject::CVertexArrayObject(const std::vector<std::array<float , 5>>& PVertices , const std::vector<std::uint32_t>& PElements)
    {
        glGenVertexArrays(1 , &FIdentifier);
        glBindVertexArray(FIdentifier);
        FVertexBufferObject.reset(new CVertexBufferObject{PVertices});
        FElementBufferObject.reset(new CElementBufferObject{PElements});
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , reinterpret_cast<void*>(3 * sizeof(float)));
        GDebug.OOpenGraphicsLibraryError();
    }
    const CVertexArrayObject& CVertexArrayObject::ORender() const
    {
        glBindVertexArray(FIdentifier);
        glDrawElements(GL_TRIANGLES , static_cast<std::int32_t>(FElementBufferObject->OSize()) , GL_UNSIGNED_INT , nullptr);
        return *this;
    }
    CVertexArrayObject::~CVertexArrayObject()
    {
        FElementBufferObject.reset();
        FVertexBufferObject.reset();
        glDeleteVertexArrays(1 , &FIdentifier);
        GDebug.OOpenGraphicsLibraryError();
    }
}