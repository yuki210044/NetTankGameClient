#include "Bullet.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), move_(XMFLOAT3(0.1f, 0, 0)), fall(0)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("TankBullet.fbx");
    assert(hModel_ >= 0);
}

//�X�V
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

//�`��
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}