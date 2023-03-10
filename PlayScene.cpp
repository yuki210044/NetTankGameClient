#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "Ground.h"
#include "RecvData.h"
#include "Charcter.h"
#include "OtherPlayer.h"
#include "Object.h"

namespace
{
	Charcter* p[2];
}

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	for (int i = 0; i < RecvData::playerList.size(); i++)
	{
		if (RecvData::playerList[i].playerNumber == RecvData::playerNum)
		{
			p[i] = Instantiate<Player>(this);
			p[i]->SetTankPos(RecvData::playerList[i].position);
			p[i]->SetObjectHandle(RecvData::playerList[i].playerNumber);
		}
		else
		{
			p[i] = Instantiate<OtherPlayer>(this);
			p[i]->SetTankPos(RecvData::playerList[i].position);
			p[i]->SetObjectHandle(RecvData::playerList[i].playerNumber);
		}
		
	}
	Instantiate<Ground>(this);
}

//更新
void PlayScene::Update()
{
	for (int i = 0; i < RecvData::updateList.size(); i++)
	{
		Charcter* c = nullptr;
		for (int j = 0; j < 1; j++)
		{
			if ( p[j]->GetObjectHandle() == RecvData::updateList[i].pUpdate.playerNumber)
			{
				c = p[j];
				break;
			}
		}
		if (c != nullptr)
		{
			switch (RecvData::updateList[i].sendContent)
			{
			case 1:
				if (RecvData::playerNum != c->GetObjectHandle())
				{
					c->SetTankPos(RecvData::updateList[i].pUpdate.position);
					c->GetCannon()->KeyInput_Cannon(RecvData::updateList[i].pUpdate.rotate_Cannon, RecvData::updateList[i].pUpdate.shoot);
					c->GetTank()->SetRotateY(RecvData::updateList[i].pUpdate.rotate_Tank);
				}
				break;
			case 2:
			{
				XMFLOAT3 pos = {0,0,0};
				Charcter* chit = nullptr;
				for (int j = 0; j < 2; j++)
				{
					if (p[j]->GetObjectHandle() == RecvData::updateList[i].h.targetPlayerNum)
					{
						chit = p[j];
					}
				}
				chit->Hit();
				break;
			}
			default:
				break;
			}
		}
	}
	RecvData::updateList.clear();
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}