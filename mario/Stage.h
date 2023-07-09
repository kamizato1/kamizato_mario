#pragma once

#include"StageBlock.h"
#include"BoxCollider.h"
#include"define.h"
#include"Item.h"

#define BACK_GROUND_NUM 110
#define STAGE_BLOCK_NUM 653

struct PLAYER_HIT_STAGE
{
    int block_num;
    bool flg;
};

struct BACK_GROUND
{
    DATA location;
    int image;
};

class Stage
{
private:

    class Item* item;
    class StageBlock* stageblock[STAGE_BLOCK_NUM];
    
    int hatena_block_image_type;
    int hatena_block_image_change_time;

    int sky_image;
    BACK_GROUND back_ground[BACK_GROUND_NUM];

public:

    Stage();
    ////デストラクタ
    ~Stage();
    //描画以外の更新を実装する
    void Update();
    //描画に関することを実装する
    void Draw(float camera_work) const;

    void DrawBackGround(float camera_work) const;
    void DrawStage(float camera_work) const;

    bool HitStage(BoxCollider* bc);

    PLAYER_HIT_STAGE PlayerHitStage(BoxCollider* bc);
    void BreakBlock(PLAYER_HIT_STAGE player_hit_stage);

};