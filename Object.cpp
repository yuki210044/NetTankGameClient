#include "Object.h"

namespace Object
{
	std::vector<obj> objList;
	int objNum = 0;

	void AddObject(GameObject* add)
	{
		objList.push_back({ add,objNum });
	}
}