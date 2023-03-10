#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "NetWork.h"
#include "OtherPlayer.h"
#include "Engine/Input.h"
namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
}
//コンストラクタ
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