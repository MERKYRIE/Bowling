#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CVertexBufferObject
    {
        private : std::uint32_t FIdentifier;
        private : std::intmax_t FSize;

        public : CVertexBufferObject(const std::vector<std::array<float , 5>>& PVertices);
        public : std::intmax_t OSize() const;
        public : ~CVertexBufferObject();
    };
}