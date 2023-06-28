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
    ////�f�X�g���N�^
    ~GameMain();

    //�`��ȊO�̍X�V����������
    void Update(Key* key) override;
    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const override;
    AbstractScene* ChangeScene() override;

};