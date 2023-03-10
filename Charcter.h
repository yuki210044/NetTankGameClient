#pragma once
#include "Engine/GameObject.h"
#include "Tank.h"
#include "Cannon.h"
#include "Charcter.h"

class Charcter : public GameObject
{
    Tank* pTank;
    Cannon* pCannon;
    int hObject;
public:
    Charcter(GameObject* parent, std::string objectName);
    //デストラクタ
    ~Charcter();

    //初期化
    void Initialize() override;

    //更新
    virtual void Update() override = 0;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetObjectHandle(int hObj) { hObject = hObj; }

    int GetObjectHandle() { return hObject; }
    Tank* GetTank() { return pTank; }
    Cannon* GetCannon() { return pCannon; }

    void SetTankPos(XMFLOAT3 pos) { pTank->SetPosition(pos); }

    void Hit();

};
