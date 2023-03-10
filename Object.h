#pragma once
#include <vector>
#include "Engine/GameObject.h"

struct obj
{
	GameObject* obj;
	int objNumber;
};
namespace Object
{
	extern std::vector<obj> objList;

	void AddObject(GameObject* add);
};

