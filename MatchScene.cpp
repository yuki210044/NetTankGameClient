#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "MatchScene.h"
#include "Engine/SceneManager.h"
#include "RecvData.h"
#include "NetWork.h"

namespace
{
	bool is = false;
}
//コンストラクタ
MatchScene::MatchScene(GameObject* parent)
	: GameObject(parent, "MatchScene")
{
}

//初期化
void MatchScene::Initialize()
{
}

//更新
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

//描画
void MatchScene::Draw()
{
}

//開放
void MatchScene::Release()
{
}