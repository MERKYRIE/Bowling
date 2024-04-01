#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CTexture;
    
    class CCharacter
    {
        friend class CFont;
        
        private : std::shared_ptr<const CTexture> FTexture;

        private : CCharacter(TTF_Font* PFont , char PCode);

        public : std::shared_ptr<const CTexture> OTexture() const;
        public : ~CCharacter();
    };
}