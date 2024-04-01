#pragma once

#include"Bowling.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    class CTexture;
    class CVertexArrayObject;
    
    class CMesh
    {
        private : std::shared_ptr<const CVertexArrayObject> FVertexArrayObject;
        private : std::shared_ptr<const CTexture> FTexture;
        private : float FPositionX;
        private : float FPositionY;
        private : float FPositionZ;
        private : float FScaleX;
        private : float FScaleY;
        private : float FScaleZ;
        private : float FRotationX;
        private : float FRotationY;
        private : float FRotationZ;
        private : float FSpeedX;
        private : float FSpeedY;
        private : float FSpeedZ;

        public : CMesh();
        public : const std::shared_ptr<const CVertexArrayObject>& OVertexArrayObject() const;
        public : const CMesh& OVertexArrayObject(const std::shared_ptr<const CVertexArrayObject>& PVertexArrayObject);
        public : const std::shared_ptr<const CTexture>& OTexture() const;
        public : const CMesh& OTexture(const std::shared_ptr<const CTexture>& PTexture);
        public : float OPositionX() const;
        public : const CMesh& OPositionX(float PValue);
        public : float OPositionY() const;
        public : const CMesh& OPositionY(float PValue);
        public : float OPositionZ() const;
        public : const CMesh& OPositionZ(float PValue);
        public : float OScaleX() const;
        public : const CMesh& OScaleX(float PValue);
        public : float OScaleY() const;
        public : const CMesh& OScaleY(float PValue);
        public : float OScaleZ() const;
        public : const CMesh& OScaleZ(float PValue);
        public : float ORotationX() const;
        public : const CMesh& ORotationX(float PValue);
        public : float ORotationY() const;
        public : const CMesh& ORotationY(float PValue);
        public : float ORotationZ() const;
        public : const CMesh& ORotationZ(float PValue);
        public : float OSpeedX() const;
        public : const CMesh& OSpeedX(float PValue);
        public : float OSpeedY() const;
        public : const CMesh& OSpeedY(float PValue);
        public : float OSpeedZ() const;
        public : const CMesh& OSpeedZ(float PValue);
        public : const CMesh& OUpdate();
        public : ~CMesh();
    };
}