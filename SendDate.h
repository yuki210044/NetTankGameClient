#pragma once
#include "Engine/Transform.h"

//Server�ɑ���f�[�^���Ǘ�����

struct SendDateToServer
{
	int playerNumber; //��P��
	XMINT3 Position;
	float rotate_Cannon;
	float rotate_Tank;
	bool     isShoot;
};

namespace SendDate
{
	extern SendDateToServer send;
};

