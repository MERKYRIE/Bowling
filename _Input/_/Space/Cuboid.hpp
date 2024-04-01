#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CMesh;
}

namespace NAdvancedEngineArchitecture::NSpace
{
    class CCuboid
    {
        private : std::shared_ptr<NVideo::CMesh> FMesh;

        public : CCuboid();
        public : const std::shared_ptr<NVideo::CMesh> OMesh() const;
        public : bool OCollides(const CCuboid& PThat) const;
        public : ~CCuboid();
    };
}