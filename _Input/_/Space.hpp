#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture
{
    namespace NSpace
    {
        class CRectangle;
        class CCuboid;
        class CSphere;
    }
    namespace NVideo
    {
        class CFont;
    }
    
    inline class CSpace
    {
        friend std::int32_t (::main(std::int32_t , char**));

        private : std::shared_ptr<NSpace::CRectangle> FLane;
        private : std::vector<std::shared_ptr<NSpace::CCuboid>> FBorders;
        private : std::vector<std::shared_ptr<NSpace::CCuboid>> FPins;
        private : std::shared_ptr<NSpace::CCuboid> FArrow;
        private : float FRotation;
        private : float FScale;
        private : std::shared_ptr<NSpace::CSphere> FBall;
        private : std::vector<bool> FHits;
        private : std::shared_ptr<const NVideo::CFont> FFont;
        private : std::shared_ptr<NSpace::CRectangle> FScore;
        private : std::uint8_t FTry;

        private : void BInitialize();
        private : void BUpdate();
        private : void BDeinitialize();
    }
    GSpace;
}