#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "NetWork.h"
#include "Charcter.h"
#include "Engine/Input.h"
namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
}
//コンストラクタ
Charcter::Charcter(GameObject* parent, std::string objectName)
	: GameObject(parent, objectName)
{
	pTank = nullptr;
}

Charcter::~Charcter()
{

}

//初期化
void Charcter::Initialize()
{
	pTank = Instantiate<Tank>(this);
	pCannon = (Cannon*)FindObject("Cannon");
}

//描画
void Charcter::Draw()
{
}

//開放
void Charcter::Release()
{
}

void Charcter::Hit()
{
	if (pTank->invincibleTime_ <= 0)
	{
		pTank->Life_--;
		pTank->invincibleTime_ = 180;
	}
}