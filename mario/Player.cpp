#include <math.h>
#include"DxLib.h"
#include"Player.h"

#define IMAGE_TYPE_FIRST 3
#define IMAGE_TYPE_LAST 4
#define IMAGE_CHANGE_TIME 3

#define PLAYER_MAX_GRAVITY 10
#define PLAYER_GRAVITY 0.7
#define MAX_SPEED 4

Player::Player()
{
	location = { 20,20 };
	size = { 22,60 };
	for (int i = 0; i < SPEED_DATA_NUM; i++)speed_data[i] = { 0,0 };
    speed = {0 , PLAYER_MAX_GRAVITY};

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
    if(CheckHitKey(KEY_INPUT_RETURN))location.y = 250;

    //x座標の移動↓

    float add_speed_x = 0;
    float now_speed_x = 0;
    float old_speed_x;
    speed.x = 0;
    if (key->KeyPressed(LEFT))speed.x = -MAX_SPEED;
    else if (key->KeyPressed(RIGHT))speed.x = MAX_SPEED;

    for (int i = 0; i < SPEED_DATA_NUM; i++)
    {
        old_speed_x = speed_data[i].x;
        speed_data[i].x = now_speed_x;
        now_speed_x = old_speed_x;
        add_speed_x += speed_data[i].x;
    }

    //speed.x = (add_speed_x / SPEED_DATA_NUM);
    if (key->KeyPressed(A))speed.x = speed.x *= 1.5; //Aボタンが押されたら歩く速さを1.5倍にする;

    if (speed.x > 0)direction_left = FALSE;
    else if (speed.x < 0)direction_left = TRUE;

    location.x += speed.x;

    if (stage->PlayerHitStage(this).flg)//障害物に当たっているとき
    {
        location.x = floor(location.x);
        float sign = -(speed.x / fabsf(speed.x));
        while (stage->PlayerHitStage(this).flg)location.x += sign;
    }

    //y座標の移動↓

    if(speed.y != PLAYER_MAX_GRAVITY)
    {
        speed.y += PLAYER_GRAVITY;
        if (speed.y > PLAYER_MAX_GRAVITY)speed.y = PLAYER_MAX_GRAVITY;
    }
    location.y += speed.y;

    PLAYER_HIT_STAGE player_hit_stage = stage->PlayerHitStage(this);

    if (player_hit_stage.flg)//マリオがブロックに当たっている
    {
        location.y = floor(location.y);
        float sign = -(speed.y / fabsf(speed.y));
        while (stage->PlayerHitStage(this).flg)location.y += sign;
        speed.y = 0;

        if (sign == -1)//地面に当たっている
        {
            if (key->KeyDown(B))speed.y = -14, image_type = 6;
            else
            {
                if (speed.x == 0)image_type = 0;//マリオが止まっているとき
                else //マリオが歩いているとき
                {
                    if (++image_change_time > IMAGE_CHANGE_TIME)
                    {
                        ++image_type;
                        if ((image_type < IMAGE_TYPE_FIRST) || (image_type > IMAGE_TYPE_LAST))image_type = IMAGE_TYPE_FIRST;
                        image_change_time = 0;
                    }
                }
            }
        }
        else //頭に当たっているとき
        {
            stage->BreakBlock(player_hit_stage.block_num);
        }
    }
}

void Player::Draw(float camera_work) const
{
    DrawFormatString(0, 0, 0xffffff, "%f", speed.x);
   DrawRotaGraph(location.x + camera_work, location.y, 1, 0, image[0][image_type], TRUE, direction_left);
}