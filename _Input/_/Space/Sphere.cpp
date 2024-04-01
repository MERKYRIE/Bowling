#include"Sphere.hpp"

#include"Cuboid.hpp"

#include"Video\\Mesh.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture::NSpace
{
    CSphere::CSphere()
    {
        FMesh.reset(new NVideo::CMesh);
        FMesh->OVertexArrayObject
        (
            std::make_shared<NVideo::CVertexArrayObject>
            (
                std::vector<std::array<float , 5>>
                {
                    {0.5F , 0.5F , 0.0F , 0.0F , 0.0F} ,
                    {0.5F , 0.0F , 0.5F , 0.0F , 0.0F} ,
                    {1.0F , 0.5F , 0.5F , 0.0F , 0.0F} ,
                    {0.5F , 1.0F , 0.5F , 0.0F , 0.0F} ,
                    {0.0F , 0.5F , 0.5F , 0.0F , 0.0F} ,
                    {0.5F , 0.5F , 1.0F , 0.0F , 0.0F}
                }
                ,
                std::vector<std::uint32_t>
                {
                     0 , 1 , 2 ,
                     0 , 2 , 3 ,
                     0 , 3 , 4 ,
                     0 , 4 , 1 ,
                     5 , 2 , 1 ,
                     5 , 3 , 2 ,
                     5 , 4 , 3 ,
                     5 , 1 , 4
                }
            )
        );
    }
    const std::shared_ptr<NVideo::CMesh> CSphere::OMesh() const
    {
        return FMesh;
    }
    bool CSphere::OCollides(const CCuboid& PThat) const
    {
        CGAL::Sphere_3<CGAL::Simple_cartesian<float>> LThis
        {
            {FMesh->OPositionX() , FMesh->OPositionY() , FMesh->OPositionZ()} ,
            (std::max({FMesh->OScaleX() , FMesh->OScaleY() , FMesh->OScaleZ()}) / 2.0F) * (std::max({FMesh->OScaleX() , FMesh->OScaleY() , FMesh->OScaleZ()}) / 2.0F)
        };
        CGAL::Iso_cuboid_3<CGAL::Simple_cartesian<float>> LThat
        {
            PThat.OMesh()->OPositionX() - PThat.OMesh()->OScaleX() / 2.0F ,
            PThat.OMesh()->OPositionY() - PThat.OMesh()->OScaleY() / 2.0F ,
            PThat.OMesh()->OPositionZ() - PThat.OMesh()->OScaleZ() / 2.0F ,
            PThat.OMesh()->OPositionX() + PThat.OMesh()->OScaleX() / 2.0F ,
            PThat.OMesh()->OPositionY() + PThat.OMesh()->OScaleY() / 2.0F ,
            PThat.OMesh()->OPositionZ() + PThat.OMesh()->OScaleZ() / 2.0F
        };
        return CGAL::do_intersect(LThis , LThat);
    }
    CSphere::~CSphere()
    {
        FMesh.reset();
    }
}