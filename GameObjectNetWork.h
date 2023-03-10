#pragma once
#include "Engine/GameObject.h"

class GameObjectNetWork : public GameObject
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameObjectNetWork(GameObject* parent, std::string objectName);

	//������
	virtual void Initialize() override = 0;

	//�X�V
	virtual void Update() override = 0;

	//�`��
	virtual void Draw() override = 0;

	//�J��
	virtual void Release() override = 0;

	//�I�u�W�F�N�g���쐬����e���v���[�g
	template <class T>
	T* InstantiateNetWork(GameObject* pParent)
	{
		return Instantiate<T>(pParent);
	}
};

