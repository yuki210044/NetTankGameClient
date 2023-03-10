#define _WINSOCKAPI_ //WinSock2�̍Ē�`���
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

//�R���X�g���N�^
Tank::Tank(GameObject* parent)
    :GameObject(parent, "Tank"), hModel_(-1), Life_(3), invincibleTime_(-1)
{
}
//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("TankBase.fbx");
    assert(hModel_ >= 0);
    pCnnon = Instantiate<Cannon>(this);

    SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 1, 0), 1.5f);
    AddCollider(collision);

    prevTrans = transform_;
}

//�X�V
void Tank::Update()
{
    prevTrans = transform_;

    XMVECTOR vMove = XMLoadFloat3(&move);//move��4�����x�N�g���ɂ���

    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));//y����],XMConvertToRadians�͉��x��rad�ɕϊ������f�B���[�g�H�ŋt����

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMove��mRotate������]����

    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);//���ݒn���x�N�g���ɂ��đ��
    vPos += vMove;//move�̒��g({ 0,0,0.1f })�𑫂�

    XMStoreFloat3(&transform_.position_, vPos);//���ݒn���ړ�����

    move = { 0,0,0 };

    //�t�B�[���h�O�ɂ����Ȃ�
    if (transform_.position_.x >= 21 || transform_.position_.x <= -21 ||
        transform_.position_.z >= 21 || transform_.position_.z <= -21)
    {
        transform_ = prevTrans;
    }

    //�n�ʂɂ���
    Ground* pGround = (Ground*)FindObject("Ground");    //�X�e�[�W�I�u�W�F�N�g��T��
    int hGroundModel = pGround->GetModelHandle();    //���f���ԍ����擾

    RayCastData data;
    data.start = transform_.position_;   //���C�̔��ˈʒu
    data.start.y = 0;
    data.dir = XMFLOAT3(0, -1, 0);       //���C�̕���
    Model::RayCast(hGroundModel, &data); //���C�𔭎�

    if (data.hit)
    {
        transform_.position_.y = -data.dist;
    }

    //���G����
    invincibleTime_--;
}

//�`��
void Tank::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}

void Tank::KeyInput(float nowMove, float rotateY)
{
        transform_.rotate_.y = rotateY;
        move.z = nowMove;
}