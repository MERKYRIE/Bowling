#include"Character.hpp"

#include"Texture.hpp"

#include"Debug.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CCharacter::CCharacter(TTF_Font* PFont , char PCode)
    {
        FTexture.reset(new CTexture{PFont , PCode});
    }

    std::shared_ptr<const NVideo::CTexture> CCharacter::OTexture() const
    {
        return(FTexture);
    }
    CCharacter::~CCharacter()
    {
        FTexture.reset();
    }
}