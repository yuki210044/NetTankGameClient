#pragma once
#include "Charcter.h"

/// <summary>
/// Charcterクラスからの継承　自身のプレイヤーキャラ用のクラス
/// </summary>
class OtherPlayer : public Charcter
{
public:
    OtherPlayer(GameObject* parent);
    //デストラクタ
    ~OtherPlayer();

    //更新
    void Update() override;
};


