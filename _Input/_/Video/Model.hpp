#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CVertexArrayObject;
    
    class CModel
    {
        friend class CVideo;
        
        private : std::string FPath;
        private : std::vector<std::vector<std::array<float , 5>>> FVertices;
        private : std::vector<std::vector<std::uint32_t>> FElements;
        private : std::vector<std::shared_ptr<CVertexArrayObject>> FVertexArrayObjects;

        private : CModel(const std::string& PPath);
        private : bool operator==(const std::string& PPath) const;

        public : const CModel& ORender() const;
        public : ~CModel();
    };
}