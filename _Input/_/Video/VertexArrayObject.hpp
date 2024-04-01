#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CVertexBufferObject;
    class CElementBufferObject;

    class CVertexArrayObject
    {
        private : std::uint32_t FIdentifier;
        private : std::shared_ptr<CVertexBufferObject> FVertexBufferObject;
        private : std::shared_ptr<CElementBufferObject> FElementBufferObject;

        public : CVertexArrayObject(const std::vector<std::array<float , 5>>& PVertices , const std::vector<std::uint32_t>& PElements);
        public : const CVertexArrayObject& ORender() const;
        public : ~CVertexArrayObject();
    };
}