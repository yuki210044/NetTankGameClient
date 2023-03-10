#pragma once
#include "Engine/GameObject.h"

class GameObjectNetWork : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameObjectNetWork(GameObject* parent, std::string objectName);

	//初期化
	virtual void Initialize() override = 0;

	//更新
	virtual void Update() override = 0;

	//描画
	virtual void Draw() override = 0;

	//開放
	virtual void Release() override = 0;

	//オブジェクトを作成するテンプレート
	template <class T>
	T* InstantiateNetWork(GameObject* pParent)
	{
		return Instantiate<T>(pParent);
	}
};

