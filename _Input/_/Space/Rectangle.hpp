#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CMesh;
}

namespace NAdvancedEngineArchitecture::NSpace
{
    class CRectangle
    {
        private : std::shared_ptr<NVideo::CMesh> FMesh;

        public : CRectangle();
        public : const std::shared_ptr<NVideo::CMesh> OMesh() const;
        public : ~CRectangle();
    };
}