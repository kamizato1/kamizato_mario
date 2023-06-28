#pragma once

#include"AbstractScene.h"
#include"Stage.h"
#include"Player.h"
#include"Key.h"
#include"define.h"

class GameMain : public AbstractScene
{
private:

    Key* key;
    Stage* stage;
    Player* player;

    bool stop;

public:

    GameMain();
    ////デストラクタ
    ~GameMain();

    //描画以外の更新を実装する
    void Update(Key* key) override;
    //描画に関することを実装する
    void Draw() const override;
    AbstractScene* ChangeScene() override;

};