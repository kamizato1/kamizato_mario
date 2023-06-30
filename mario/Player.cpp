#include <math.h>
#include"DxLib.h"
#include"Player.h"

#define MAX_SPEED 4
#define ACCELERATION_SPEED 0.15

#define IMAGE_TYPE_FIRST 3
#define IMAGE_TYPE_LAST 4
#define IMAGE_CHANGE_TIME 3

Player::Player()
{
	location = { 20,20 };
	size = { 32,64 };
	//for (int i = 0; i < SPEED_DATA_NUM; i++)speed_data[i] = { 0,0 };
    speed = {0 , 0};

    int image[54];
    LoadDivGraph("image/Mario/big_mario.png", 54, 9, 6, 32, 64, image);
    int a = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->image[i][j] = image[a];
            a++;
        }
    }

    image_change_time = 0;
    image_type = 0;
    direction_left = FALSE;
}

void Player::Update(Key* key, Stage* stage)
{
    //x座標の移動↓

   /* float add_speed_x = 0;
    float now_speed_x = 0;
    float old_speed_x;
    if (key->KeyPressed(LEFT))now_speed_x = -MAX_SPEED;
    else if (key->KeyPressed(RIGHT))now_speed_x = MAX_SPEED;

    for (int i = 0; i < SPEED_DATA_NUM; i++)
    {
        old_speed_x = speed_data[i].x;
        speed_data[i].x = now_speed_x;
        now_speed_x = old_speed_x;
        add_speed_x += speed_data[i].x;
    }

    speed.x = (add_speed_x / SPEED_DATA_NUM);*/

    int sign = 0;
    if (key->KeyPressed(RIGHT)) sign = 1;
    else if (key->KeyPressed(LEFT)) sign = -1;

    if (speed.x != 0)//マリオが歩いているとき
    {
        if (++image_change_time > IMAGE_CHANGE_TIME)
        {
            ++image_type;
            if ((image_type < IMAGE_TYPE_FIRST) || (image_type > IMAGE_TYPE_LAST))image_type = IMAGE_TYPE_FIRST;
            image_change_time = 0;
        }
    }
    else image_type = 0;//マリオが止まっているとき


    if (sign == 1)
    {
        speed.x += ACCELERATION_SPEED;
        if (speed.x > MAX_SPEED)speed.x = MAX_SPEED;

        if (speed.x >= 0)direction_left = FALSE;
        else image_type = 5;
    }
    else
    {
        if (speed.x > 0)
        {
            speed.x -= ACCELERATION_SPEED;
            if (speed.x < 0)speed.x = 0;
        }
    }

    if (sign == -1)
    {
        speed.x -= ACCELERATION_SPEED;
        if (speed.x < -MAX_SPEED)speed.x = -MAX_SPEED;

        if (speed.x <= 0)direction_left = TRUE;
        else image_type = 5;
    }
    else
    {
        if (speed.x < 0)
        {
            speed.x += ACCELERATION_SPEED;
            if (speed.x > 0)speed.x = 0;
        }
    }


    



    location.x += speed.x;

    if (stage->HitStage(this))//障害物に当たっているとき
    {
        location.x = floor(location.x);
        float sign = -(speed.x / fabsf(speed.x));
        while (stage->HitStage(this))location.x += sign;
    }


    //y座標の移動↓

    speed.y += GRAVITY;
    location.y += speed.y;

    if (stage->HitStage(this))
    {
        location.y = floor(location.y);
        float sign = -(speed.y / fabsf(speed.y));

        speed.y = 0;
        if (sign == -1)//地面についているとき
        {
            if (key->KeyDown(B))speed.y = -13;
        }
        else //頭に当たっているとき
        {
            stage->BreakBlock(this);
            image_type = 6;
        }

        while (stage->HitStage(this))location.y += sign;
    }
    else image_type = 6;
}

void Player::Draw(float camera_work) const
{
    DrawFormatString(0, 0, 0xffffff, "%f", speed.x);
   DrawRotaGraph(location.x + camera_work, location.y, 1, 0, image[0][image_type], TRUE, direction_left);
}