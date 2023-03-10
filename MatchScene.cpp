#define _WINSOCKAPI_ //WinSock2�̍Ē�`���
#include "MatchScene.h"
#include "Engine/SceneManager.h"
#include "RecvData.h"
#include "NetWork.h"

namespace
{
	bool is = false;
}
//�R���X�g���N�^
MatchScene::MatchScene(GameObject* parent)
	: GameObject(parent, "MatchScene")
{
}

//������
void MatchScene::Initialize()
{
}

//�X�V
void MatchScene::Update()
{
	
    if (RecvData::playerList.size() == PLAYERMENBER)
    {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(PLAY);
	}
	else
	{
		NetWork::InitSend();
		NetWork::InitRecv();
	}
	
	
	
}

//�`��
void MatchScene::Draw()
{
}

//�J��
void MatchScene::Release()
{
}