#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "NetWork.h"
#include "Tank.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Ground.h"
#include "Engine/SphereCollider.h"



namespace
{
    XMFLOAT3 move = { 0,0,0 };
    Transform prevTrans;
}

//コンストラクタ
Tank::Tank(GameObject* parent)
    :GameObject(parent, "Tank"), hModel_(-1), Life_(3), invincibleTime_(-1)
{
}
//デストラクタ
Tank::~Tank()
{
}

//初期化
void Tank::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("TankBase.fbx");
    assert(hModel_ >= 0);
    pCnnon = Instantiate<Cannon>(this);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1, 0), 1.5f);
    AddCollider(collision);

    prevTrans = transform_;
}

//更新
void Tank::Update()
{
    prevTrans = transform_;

    XMVECTOR vMove = XMLoadFloat3(&move);//moveを4次元ベクトルにする

    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//y軸回転,XMConvertToRadiansは何度をradに変換するやつディレート？で逆も可

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMoveをmRotateだけ回転する

    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//現在地をベクトルにして代入
    vPos += vMove;//moveの中身({ 0,0,0.1f })を足す

    XMStoreFloat3(&transform_.position_, vPos);//現在地を移動する

    move = { 0,0,0 };

    //フィールド外にださない
    if (transform_.position_.x >= 21 || transform_.position_.x <= -21 ||
        transform_.position_.z >= 21 || transform_.position_.z <= -21)
    {
        transform_ = prevTrans;
    }

    //地面につける
    Ground* pGround = (Ground*)FindObject("Ground");    //ステージオブジェクトを探す
    int hGroundModel = pGround->GetModelHandle();    //モデル番号を取得

    RayCastData data;
    data.start = transform_.position_;   //レイの発射位置
    data.start.y = 0;
    data.dir = XMFLOAT3(0, -1, 0);       //レイの方向
    Model::RayCast(hGroundModel, &data); //レイを発射

    if (data.hit)
    {
        transform_.position_.y = -data.dist;
    }

    //無敵時間
    invincibleTime_--;
}

//描画
void Tank::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Tank::Release()
{
}

void Tank::KeyInput(float nowMove, float rotateY)
{
        transform_.rotate_.y = rotateY;
        move.z = nowMove;
}