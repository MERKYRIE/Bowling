#include"Rectangle.hpp"

#include"Video\\Mesh.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture::NSpace
{
    CRectangle::CRectangle()
    {
        FMesh.reset(new NVideo::CMesh);
        FMesh->OVertexArrayObject
        (
            std::make_shared<NVideo::CVertexArrayObject>
            (
                std::vector<std::array<float , 5>>
                {
                    {0.0F , 0.0F , 0.0F , 0.0F , 1.0F} ,
                    {0.0F , 1.0F , 0.0F , 0.0F , 0.0F} ,
                    {1.0F , 1.0F , 0.0F , 1.0F , 0.0F} ,
                    {1.0F , 0.0F , 0.0F , 1.0F , 1.0F}
                }
                ,
                std::vector<std::uint32_t>
                {
                    0 , 1 , 2 , 2 , 3 , 0
                }
            )
        );
    }
    const std::shared_ptr<NVideo::CMesh> CRectangle::OMesh() const
    {
        return FMesh;
    }
    CRectangle::~CRectangle()
    {
        FMesh.reset();
    }
}