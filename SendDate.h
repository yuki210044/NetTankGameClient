#pragma once
#include "Engine/Transform.h"

//Server‚É‘—‚éƒf[ƒ^‚ğŠÇ—‚·‚é

struct SendDateToServer
{
	int playerNumber; //‰½P‚©
	XMINT3 Position;
	float rotate_Cannon;
	float rotate_Tank;
	bool     isShoot;
};

namespace SendDate
{
	extern SendDateToServer send;
};

