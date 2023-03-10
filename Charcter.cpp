#define _WINSOCKAPI_ //WinSock2�̍Ē�`���
#include "NetWork.h"
#include "Charcter.h"
#include "Engine/Input.h"
namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
}
//�R���X�g���N�^
Charcter::Charcter(GameObject* parent, std::string objectName)
	: GameObject(parent, objectName)
{
	pTank = nullptr;
}

Charcter::~Charcter()
{

}

//������
void Charcter::Initialize()
{
	pTank = Instantiate<Tank>(this);
	pCannon = (Cannon*)FindObject("Cannon");
}

//�`��
void Charcter::Draw()
{
}

//�J��
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