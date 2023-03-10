#pragma once
#include "Charcter.h"

/// <summary>
/// Charcterクラスからの継承　自身のプレイヤーキャラ用のクラス
/// </summary>
class Player : public Charcter
{
public:
	Player(GameObject* parent);
    //デストラクタ
    ~Player();

    //更新
    void Update() override;
};

