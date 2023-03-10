#pragma once
#include "Engine/Transform.h"
#include <iostream>
#include <vector>

struct RecvInitData_Player
{
	int playerNumber; //��P��
	XMFLOAT3 position; //�ʒu
};

struct RecvUpdateData_Player
{
	int playerNumber; //��P��
	XMFLOAT3 position; //�ʒu
	float rotate_Tank; //�^���N��]
	float rotate_Cannon; //�C�g��]
	bool shoot;
};

struct RecvHitData
{
	bool isHit;
	int targetPlayerNum;
	int objNum;
	XMFLOAT3 position;
	int hitReaction; //�����������̏���
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

