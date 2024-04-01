#include"Model.hpp"

#include"VertexArrayObject.hpp"

#include"Debug.hpp"

namespace NAdvancedEngineArchitecture::NVideo
{
    CModel::CModel(const std::string& PPath)
    {
        FPath = PPath.substr(PPath.find('\\'));
        const aiScene* LScene{aiImportFile(PPath.c_str() , 0)};
        GDebug.OOpenAssetImportLibraryError(LScene);
        FVertices.resize(LScene->mNumMeshes);
        FElements.resize(LScene->mNumMeshes);
        FVertexArrayObjects.resize(LScene->mNumMeshes);
        for(std::uint32_t LMesh{0} ; LMesh < LScene->mNumMeshes ; LMesh++)
        {
            FVertices[LMesh].resize(LScene->mMeshes[LMesh]->mNumVertices);
            for(std::uint32_t LVertex{0} ; LVertex < LScene->mMeshes[LMesh]->mNumVertices ; LVertex++)
            {
                FVertices[LMesh][LVertex] = {LScene->mMeshes[LMesh]->mVertices[LVertex].x , LScene->mMeshes[LMesh]->mVertices[LVertex].y , LScene->mMeshes[LMesh]->mVertices[LVertex].z , 0.0F , 0.0F};
            }
            FVertices[LMesh].shrink_to_fit();
            FElements[LMesh].resize(LScene->mMeshes[LMesh]->mNumFaces * 3);
            for(std::uint32_t LFace{0} ; LFace < LScene->mMeshes[LMesh]->mNumFaces ; LFace++)
            {
                for(std::uint32_t LElement{0} ; LElement < 3 ; LElement++)
                {
                    FElements[LMesh][LFace * 3 + LElement] = LScene->mMeshes[LMesh]->mFaces[LFace].mIndices[LElement];
                }
            }
            FElements[LMesh].shrink_to_fit();
            FVertexArrayObjects[LMesh].reset
            (
                new CVertexArrayObject
                {
                    FVertices[LMesh] , FElements[LMesh]
                }
            );
        }
        FVertexArrayObjects.shrink_to_fit();
        FElements.shrink_to_fit();
        FVertices.shrink_to_fit();
        aiReleaseImport(LScene);
    }
    bool CModel::operator==(const std::string& PPath) const
    {
        return(FPath == PPath);
    }

    const CModel& CModel::ORender() const
    {
        for(std::uintmax_t LMesh{0} ; LMesh < FVertexArrayObjects.size() ; LMesh++)
        {
            glBindTexture(GL_TEXTURE_2D , 0);
            FVertexArrayObjects[LMesh]->ORender();
        }
        return *this;
    }
    CModel::~CModel()
    {
        FVertexArrayObjects.clear();
    }
}