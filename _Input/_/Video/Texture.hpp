#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CTexture
    {
        friend class CVideo;
        friend class CCharacter;
        
        private : std::string FPath;
        private : std::uint32_t FIdentifier;

        private : CTexture(const std::string& PPath);
        private : CTexture(TTF_Font* PFont , char PCode);
        private : bool operator==(const std::string& PPath) const;

        public : std::uint32_t OIdentifier() const;
        public : ~CTexture();
    };
}