#pragma once
#include "Engine/Transform.h"

//Serverに送るデータを管理する

struct SendDateToServer
{
	int playerNumber; //何Pか
	XMINT3 Position;
	float rotate_Cannon;
	float rotate_Tank;
	bool     isShoot;
};

namespace SendDate
{
	extern SendDateToServer send;
};

