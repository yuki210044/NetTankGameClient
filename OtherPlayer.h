#pragma once
#include "Charcter.h"

/// <summary>
/// Charcter�N���X����̌p���@���g�̃v���C���[�L�����p�̃N���X
/// </summary>
class OtherPlayer : public Charcter
{
public:
    OtherPlayer(GameObject* parent);
    //�f�X�g���N�^
    ~OtherPlayer();

    //�X�V
    void Update() override;
};


