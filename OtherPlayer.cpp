#define _WINSOCKAPI_ //WinSock2�̍Ē�`���
#include "NetWork.h"
#include "OtherPlayer.h"
#include "Engine/Input.h"
namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
}
//�R���X�g���N�^
OtherPlayer::OtherPlayer(GameObject* parent)
	: Charcter(parent, "OtherPlayer")
{
}

OtherPlayer::~OtherPlayer()
{

}

void OtherPlayer::Update()
{

}