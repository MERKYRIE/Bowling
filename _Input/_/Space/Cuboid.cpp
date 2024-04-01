#include"Cuboid.hpp"

#include"Video\\Mesh.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture::NSpace
{
    CCuboid::CCuboid()
    {
        FMesh.reset(new NVideo::CMesh);
        FMesh->OVertexArrayObject
        (
            std::make_shared<NVideo::CVertexArrayObject>
            (
                std::vector<std::array<float , 5>>
                {
                    {0.0F , 1.0F , 0.0F , 0.0F , 1.0F} ,
                    {0.0F , 1.0F , 1.0F , 0.0F , 0.0F} ,
                    {0.0F , 0.0F , 1.0F , 1.0F , 0.0F} ,
                    {0.0F , 0.0F , 0.0F , 1.0F , 1.0F} ,
                    {1.0F , 0.0F , 0.0F , 1.0F , 1.0F} ,
                    {1.0F , 0.0F , 1.0F , 1.0F , 0.0F} ,
                    {1.0F , 1.0F , 1.0F , 0.0F , 0.0F} ,
                    {1.0F , 1.0F , 0.0F , 0.0F , 1.0F} ,
                    {0.0F , 0.0F , 0.0F , 0.0F , 1.0F} ,
                    {0.0F , 0.0F , 1.0F , 0.0F , 0.0F} ,
                    {1.0F , 0.0F , 1.0F , 1.0F , 0.0F} ,
                    {1.0F , 0.0F , 0.0F , 1.0F , 1.0F} ,
                    {1.0F , 1.0F , 0.0F , 1.0F , 1.0F} ,
                    {1.0F , 1.0F , 1.0F , 1.0F , 0.0F} ,
                    {0.0F , 1.0F , 1.0F , 0.0F , 0.0F} ,
                    {0.0F , 1.0F , 0.0F , 0.0F , 1.0F} ,
                    {0.0F , 1.0F , 0.0F , 0.0F , 0.0F} ,
                    {0.0F , 0.0F , 0.0F , 0.0F , 1.0F} ,
                    {1.0F , 0.0F , 0.0F , 1.0F , 1.0F} ,
                    {1.0F , 1.0F , 0.0F , 1.0F , 0.0F} ,
                    {0.0F , 0.0F , 1.0F , 0.0F , 1.0F} ,
                    {0.0F , 1.0F , 1.0F , 0.0F , 0.0F} ,
                    {1.0F , 1.0F , 1.0F , 1.0F , 0.0F} ,
                    {1.0F , 0.0F , 1.0F , 1.0F , 1.0F}
                }
                ,
                std::vector<std::uint32_t>
                {
                     0 ,  1 ,  2 ,  2 ,  3 ,  0 ,
                     4 ,  5 ,  6 ,  6 ,  7 ,  4 ,
                     8 ,  9 , 10 , 10 , 11 ,  8 ,
                    12 , 13 , 14 , 14 , 15 , 12 ,
                    16 , 17 , 18 , 18 , 19 , 16 ,
                    20 , 21 , 22 , 22 , 23 , 20
                }
            )
        );
    }
    const std::shared_ptr<NVideo::CMesh> CCuboid::OMesh() const
    {
        return FMesh;
    }
    bool CCuboid::OCollides(const CCuboid& PThat) const
    {
        CGAL::Iso_cuboid_3<CGAL::Simple_cartesian<float>> LThis
        {
            FMesh->OPositionX() - FMesh->OScaleX() / 2.0F , FMesh->OPositionY() - FMesh->OScaleY() / 2.0F , FMesh->OPositionZ() - FMesh->OScaleZ() / 2.0F ,
            FMesh->OPositionX() + FMesh->OScaleX() / 2.0F , FMesh->OPositionY() + FMesh->OScaleY() / 2.0F , FMesh->OPositionZ() + FMesh->OScaleZ() / 2.0F
        };
        CGAL::Iso_cuboid_3<CGAL::Simple_cartesian<float>> LThat
        {
            PThat.FMesh->OPositionX() - PThat.FMesh->OScaleX() / 2.0F , PThat.FMesh->OPositionY() - PThat.FMesh->OScaleY() / 2.0F , PThat.FMesh->OPositionZ() - PThat.FMesh->OScaleZ() / 2.0F ,
            PThat.FMesh->OPositionX() + PThat.FMesh->OScaleX() / 2.0F , PThat.FMesh->OPositionY() + PThat.FMesh->OScaleY() / 2.0F , PThat.FMesh->OPositionZ() + PThat.FMesh->OScaleZ() / 2.0F
        };
        return CGAL::do_intersect(LThis , LThat);
    }
    CCuboid::~CCuboid()
    {
        FMesh.reset();
    }
}