#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "NetWork.h"
#include "Player.h"
#include "Engine/Input.h"
namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
}
//コンストラクタ
Player::Player(GameObject* parent)
	: Charcter(parent, "Player")
{
}

Player::~Player()
{

}

//更新
void Player::Update()
{
	float move = 0;
	if (Input::IsKey(DIK_W))
	{
		move += 0.1f;
	}
	if (Input::IsKey(DIK_S))
	{
		move += -0.1f;
	}
	if (Input::IsKey(DIK_A))
	{
		rotateTank += -1;

	}
	if (Input::IsKey(DIK_D))
	{
		rotateTank += 1;
	}
	Tank* pt = GetTank();
	pt->KeyInput(move, rotateTank);

	Cannon* pc = GetCannon();

	bool isKey = false;

	if (Input::IsKey(DIK_SPACE))
	{
		isKey = true;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		rotateCannon = 1;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		rotateCannon = -1;
	}
	
	pc->KeyInput_Cannon(isKey, rotateCannon);
	rotateCannon = 0;
	Transform t = transform_;
	t.position_.x = (pt->GetPosition().x * 10);
	t.position_.y = (pt->GetPosition().y * 10);
	t.position_.z = (pt->GetPosition().z * 10);
	t.rotate_.x = pt->GetRotate().x;
	t.rotate_.y = pt->GetRotate().y;
	t.rotate_.z = pt->GetRotate().z;
	t.scale_.x = pt->GetScale().x;
	t.scale_.y = pt->GetScale().y;
	t.scale_.z = pt->GetScale().z;

	SendDate::send.isShoot = isKey;
	SendDate::send.playerNumber = GetObjectHandle();
	SendDate::send.Position.x = (int)t.position_.x;
	SendDate::send.Position.y = (int)t.position_.y;
	SendDate::send.Position.z = (int)t.position_.z;
	SendDate::send.rotate_Cannon = pc->GetRotate().y;
	SendDate::send.rotate_Tank = pt->GetRotate().y;

	NetWork::UpdateSend();
}