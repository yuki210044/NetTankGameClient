#pragma once
#include "Charcter.h"

/// <summary>
/// Charcter�N���X����̌p���@���g�̃v���C���[�L�����p�̃N���X
/// </summary>
class Player : public Charcter
{
public:
	Player(GameObject* parent);
    //�f�X�g���N�^
    ~Player();

    //�X�V
    void Update() override;
};

