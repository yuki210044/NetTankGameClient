#pragma once
#include "Move.h"

class Move_Tank : public Move
{
public:
	void MoveSelect(int move, XMFLOAT3* trans, XMFLOAT3* rotate) override;
};

