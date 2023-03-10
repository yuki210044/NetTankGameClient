#pragma once
#include "Engine/Transform.h"
#include <iostream>
#include <vector>

struct RecvInitData_Player
{
	int playerNumber; //何Pか
	XMFLOAT3 position; //位置
};

struct RecvUpdateData_Player
{
	int playerNumber; //何Pか
	XMFLOAT3 position; //位置
	float rotate_Tank; //タンク回転
	float rotate_Cannon; //砲身回転
	bool shoot;
};

struct RecvHitData
{
	bool isHit;
	int targetPlayerNum;
	int objNum;
	XMFLOAT3 position;
	int hitReaction; //当たった時の処理
};

struct RecvCorrespondence
{
	int sendContent;
	RecvInitData_Player pInit;
	RecvUpdateData_Player pUpdate;
	RecvHitData h;
};

namespace RecvData
{
	extern std::vector<RecvInitData_Player> playerList;
	extern int playerNum;
	extern std::vector<RecvCorrespondence> updateList;
};

