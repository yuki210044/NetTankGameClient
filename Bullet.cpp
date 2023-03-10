#include "Bullet.h"
#include "Engine/Model.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), move_(XMFLOAT3(0.1f, 0, 0)), fall(0)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("TankBullet.fbx");
    assert(hModel_ >= 0);
}

//更新
void Bullet::Update()
{
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

    XMVECTOR vMove = XMLoadFloat3(&move_);
    XMStoreFloat3(&transform_.position_, vPos + vMove);

    transform_.position_.y -= fall;
    fall += 0.01;
    if (transform_.position_.y <= -5)
        KillMe();
}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}