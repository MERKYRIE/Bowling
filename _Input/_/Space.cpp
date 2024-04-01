#include"Space.hpp"

#include"Debug.hpp"
#include"Input.hpp"
#include"Space\\Cuboid.hpp"
#include"Space\\Rectangle.hpp"
#include"Space\\Sphere.hpp"
#include"Time.hpp"
#include"Video.hpp"
#include"Video\\Character.hpp"
#include"Video\\Font.hpp"
#include"Video\\Mesh.hpp"
#include"Video\\VertexArrayObject.hpp"

namespace NAdvancedEngineArchitecture
{
    void CSpace::BInitialize()
    {
        FLane.reset(new NSpace::CRectangle);
        FLane->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Lane.png"));
        FLane->OMesh()->OScaleX(1.0F);
        FLane->OMesh()->OScaleY(12.0F);
        FLane->OMesh()->OScaleZ(0.0F);
        FLane->OMesh()->OPositionX(0.0F);
        FLane->OMesh()->OPositionY(6.0F);
        FLane->OMesh()->OPositionZ(0.0F);
        FBorders.resize(2);
        for(std::shared_ptr<NSpace::CCuboid>& LBorder : FBorders)
        {
            LBorder.reset(new NSpace::CCuboid);
            LBorder->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Border.png"));
            LBorder->OMesh()->OScaleX(0.25F);
            LBorder->OMesh()->OScaleY(12.0F);
            LBorder->OMesh()->OScaleZ(0.25F);
            LBorder->OMesh()->OPositionY(6.0F);
            LBorder->OMesh()->OPositionZ(0.125F);
        }
        FBorders[0]->OMesh()->OPositionX(-0.625F);
        FBorders[1]->OMesh()->OPositionX(+0.625F);
        FPins.resize(6);
        for(std::shared_ptr<NSpace::CCuboid>& LPin : FPins)
        {
            LPin.reset(new NSpace::CCuboid);
            LPin->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Pin.png"));
            LPin->OMesh()->OScaleX(0.0625F);
            LPin->OMesh()->OScaleY(0.0625F);
            LPin->OMesh()->OScaleZ(0.25F);
            LPin->OMesh()->OPositionZ(0.125F);
        }
        FPins[0]->OMesh()->OPositionX(0.0F);
        FPins[0]->OMesh()->OPositionY(11.0F);
        FPins[1]->OMesh()->OPositionX(-0.25F);
        FPins[1]->OMesh()->OPositionY(11.0F);
        FPins[2]->OMesh()->OPositionX(+0.25F);
        FPins[2]->OMesh()->OPositionY(11.0F);
        FPins[3]->OMesh()->OPositionX(-0.125F);
        FPins[3]->OMesh()->OPositionY(10.0F);
        FPins[4]->OMesh()->OPositionX(+0.125F);
        FPins[4]->OMesh()->OPositionY(10.0F);
        FPins[5]->OMesh()->OPositionX(0.0F);
        FPins[5]->OMesh()->OPositionY(9.0F);
        FArrow.reset(new NSpace::CCuboid);
        FArrow->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Arrow.png"));
        FArrow->OMesh()->OScaleX(0.015625F);
        FArrow->OMesh()->OScaleY(1.0F);
        FArrow->OMesh()->OScaleZ(0.015625F);
        FArrow->OMesh()->OPositionX(0.0F);
        FArrow->OMesh()->OPositionY(1.5F);
        FArrow->OMesh()->OPositionZ(0.0F);
        FScale = 1.0F;
        FHits.resize(6);
        FFont = GVideo.OAccessFont("\\Consolas.ttf");
        FScore.reset(new NSpace::CRectangle);
        FScore->OMesh()->OTexture(FFont->OAccessDigit('0')->OTexture());
        FScore->OMesh()->OScaleX(0.05F);
        FScore->OMesh()->OScaleY(0.05F);
        FScore->OMesh()->OScaleZ(0.0F);
        FScore->OMesh()->OPositionX(0.95F);
        FScore->OMesh()->OPositionY(0.05F);
        FScore->OMesh()->OPositionZ(0.0F);
    }
    void CSpace::BUpdate()
    {
        glEnable(GL_DEPTH_TEST);
        glm::mat4 LProjection{glm::perspective(glm::radians(90.0F) , GVideo.ORatio() , 0.25F , 1'000.0F)};
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        glm::mat4 LView{1.0F};
        LView = glm::rotate(LView , glm::radians(-90.0F) , glm::vec3{1.0F , 0.0F , 0.0F});
        LView = glm::translate(LView , -glm::vec3{0.0F , 0.0F , 1.0F});
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        FLane->OMesh()->OUpdate();
        std::ranges::for_each(FBorders , [&](const std::shared_ptr<const NSpace::CCuboid>& PBorder){PBorder->OMesh()->OUpdate();});
        if(FArrow)
        {
            if(GInput.OIsKeyHeld(SDL_SCANCODE_A))
            {
                FRotation += GTime.ORelative() * 0.25F;
                if(FRotation > +10.0F)
                {
                    FRotation = +10.0F;
                }
            }
            if(GInput.OIsKeyHeld(SDL_SCANCODE_D))
            {
                FRotation -= GTime.ORelative() * 0.25F;
                if(FRotation < -10.0F)
                {
                    FRotation = -10.0F;
                }
            }
            if(GInput.OIsKeyHeld(SDL_SCANCODE_S))
            {
                FScale -= GTime.ORelative() * 0.00390625F;
                if(FScale < 0.5F)
                {
                    FScale = 0.5F;
                }
            }
            if(GInput.OIsKeyHeld(SDL_SCANCODE_W))
            {
                FScale += GTime.ORelative() * 0.00390625F;
                if(FScale > 1.0F)
                {
                    FScale = 1.0F;
                }
            }
            FArrow->OMesh()->ORotationZ(FRotation);
            FArrow->OMesh()->OScaleY(FScale);
            FArrow->OMesh()->OPositionY(FArrow->OMesh()->OScaleY() + 0.5F);
            FArrow->OMesh()->OUpdate();
            if(GInput.OIsKeyHeld(SDL_SCANCODE_SPACE))
            {
                FArrow.reset();
                FBall.reset(new NSpace::CSphere);
                FBall->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Ball.png"));
                FBall->OMesh()->OScaleX(0.25F);
                FBall->OMesh()->OScaleY(0.25F);
                FBall->OMesh()->OScaleZ(0.25F);
                FBall->OMesh()->OPositionX(0.0F);
                FBall->OMesh()->OPositionY(1.0F);
                FBall->OMesh()->OPositionZ(0.125F);
                FBall->OMesh()->OSpeedX(-std::sin(FRotation * std::numbers::pi_v<float> / 180.0F) * FScale);
                FBall->OMesh()->OSpeedY(+std::cos(FRotation * std::numbers::pi_v<float> / 180.0F) * FScale);
                FTry++;
            }
        }
        if(FBall)
        {
            for(const std::shared_ptr<const NSpace::CCuboid>& LBorder : FBorders)
            {
                if(FBall->OCollides(*LBorder))
                {
                    FBall->OMesh()->OSpeedX(0.0F);
                }
            }
            FBall->OMesh()->OUpdate();
            for(std::uintmax_t LPin{0} ; LPin < FPins.size() ; LPin++)
            {
                if(FBall->OCollides(*FPins[LPin]))
                {
                    FPins[LPin]->OMesh()->OSpeedX(FBall->OMesh()->OSpeedX());
                    FPins[LPin]->OMesh()->OSpeedY(FBall->OMesh()->OSpeedY());
                    FHits[LPin] = true;
                }
            }
            FScore->OMesh()->OTexture(FFont->OAccessDigit('0' + std::ranges::count(FHits , true))->OTexture());
            for(const std::shared_ptr<const NSpace::CCuboid>& LA : FPins)
            {
                for(const std::shared_ptr<const NSpace::CCuboid>& LB : FPins)
                {
                    if(LA != LB)
                    {
                        if(LA->OCollides(*LB))
                        {
                            LB->OMesh()->OSpeedX(LB->OMesh()->OSpeedX() + LA->OMesh()->OSpeedX());
                            LB->OMesh()->OSpeedY(LB->OMesh()->OSpeedY() + LA->OMesh()->OSpeedY());
                        }
                    }
                }
            }
            if(FBall->OMesh()->OSpeedY() < 0.0009765625F)
            {
                FBall.reset();
                FArrow.reset(new NSpace::CCuboid);
                FArrow->OMesh()->OTexture(GVideo.OAccessSpecificTexture("\\Arrow.png"));
                FArrow->OMesh()->OScaleX(0.015625F);
                FArrow->OMesh()->OScaleY(1.0F);
                FArrow->OMesh()->OScaleZ(0.015625F);
                FArrow->OMesh()->OPositionX(0.0F);
                FArrow->OMesh()->OPositionY(1.5F);
                FArrow->OMesh()->OPositionZ(0.0F);
                FScale = 1.0F;
                FRotation = 0.0F;
                if(FTry == 2)
                {
                    FTry = 0;
                    for(const std::shared_ptr<const NSpace::CCuboid>& LPin : FPins)
                    {
                        LPin->OMesh()->OSpeedX(0.0F);
                        LPin->OMesh()->OSpeedY(0.0F);
                    }
                    FPins[0]->OMesh()->OPositionX(0.0F);
                    FPins[0]->OMesh()->OPositionY(11.0F);
                    FPins[1]->OMesh()->OPositionX(-0.25F);
                    FPins[1]->OMesh()->OPositionY(11.0F);
                    FPins[2]->OMesh()->OPositionX(+0.25F);
                    FPins[2]->OMesh()->OPositionY(11.0F);
                    FPins[3]->OMesh()->OPositionX(-0.125F);
                    FPins[3]->OMesh()->OPositionY(10.0F);
                    FPins[4]->OMesh()->OPositionX(+0.125F);
                    FPins[4]->OMesh()->OPositionY(10.0F);
                    FPins[5]->OMesh()->OPositionX(0.0F);
                    FPins[5]->OMesh()->OPositionY(9.0F);
                    std::fill(FHits.begin() , FHits.end() , false);
                    FScore->OMesh()->OTexture(FFont->OAccessDigit('0')->OTexture());
                }
            }
        }
        std::ranges::for_each(FPins , [&](const std::shared_ptr<const NSpace::CCuboid>& PPin){PPin->OMesh()->OUpdate();});
        glDisable(GL_DEPTH_TEST);
        LProjection = glm::ortho(0.0F , 1.0F , 1.0F , 0.0F);
        glUniformMatrix4fv(3 , 1 , GL_FALSE , &LProjection[0][0]);
        LView = glm::mat4{1.0F};
        glUniformMatrix4fv(4 , 1 , GL_FALSE , &LView[0][0]);
        FScore->OMesh()->OUpdate();
    }
    void CSpace::BDeinitialize()
    {
        FScore.reset();
        FFont.reset();
        FBall.reset();
        FArrow.reset();
        FPins.clear();
        FBorders.clear();
        FLane.reset();
    }
}