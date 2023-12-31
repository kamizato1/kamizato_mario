#pragma once

#include"BoxCollider.h"
#include"Stage.h"
#include"Key.h"
#include"define.h"

#define SPEED_DATA_NUM 15

class Player : public BoxCollider
{
private:

    int image[6][9];
    //DATA speed_data[SPEED_DATA_NUM];
    DATA speed;
    int image_change_time;
    int image_type;
    bool direction_left;

public:

    Player();

    //描画以外の更新を実装する
    void Update(Key* key, Stage* stage);
    //描画に関することを実装する
    void Draw(float camera_work) const;
};