#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture
{
    namespace NVideo
    {
        class CFont;
        class CModel;
        class CShader;
        class CTexture;
    }
    
    inline class CVideo
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : SDL_Window* FWindow;
        private : SDL_GLContext FContext;
        private : float FRatio;
        private : float FInversedRatio;
        private : std::shared_ptr<NVideo::CShader> FVertex;
        private : std::shared_ptr<NVideo::CShader> FFragment;
        private : std::uint32_t FProgram;
        private : std::vector<std::shared_ptr<NVideo::CFont>> FFonts;
        private : std::vector<std::shared_ptr<NVideo::CTexture>> FTextures;
        private : std::vector<std::shared_ptr<NVideo::CModel>> FModels;

        private : void BInitialize();
        private : void BPreupdate();
        private : void BPostupdate();
        private : void BDeinitialize();

        public : float ORatio();
        public : float OInversedRatio();
        public : std::shared_ptr<const NVideo::CFont> OAccessFont(const std::string& PPath);
        public : std::shared_ptr<const NVideo::CTexture> OAccessSpecificTexture(const std::string& PPath);
        public : std::shared_ptr<const NVideo::CTexture> OAccessRandomTexture();
        public : std::shared_ptr<const NVideo::CModel> OAccessModel(const std::string& PPath);
    }
    GVideo;
}