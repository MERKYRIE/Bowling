#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture
{
    namespace NSpace
    {
        class CCuboid;
    }
    namespace NVideo
    {
        class CMesh;
    }
}

namespace NAdvancedEngineArchitecture::NSpace
{
    class CSphere
    {
        private : std::shared_ptr<NVideo::CMesh> FMesh;

        public : CSphere();
        public : const std::shared_ptr<NVideo::CMesh> OMesh() const;
        public : bool OCollides(const CCuboid& PThat) const;
        public : ~CSphere();
    };
}