#pragma once

#include"StageBlock.h"
#include"BoxCollider.h"
#include"define.h"
#include"Item.h"

struct PLAYER_HIT_STAGE
{
    int y, x;
    bool flg;
};

class Stage
{
private:

    class Item* item;
    class StageBlock* stageblock[STAGE_BLOCK_NUM_Y][STAGE_BLOCK_NUM_X];
    
    int hatena_block_image_type;
    int hatena_block_image_change_time;

public:

    Stage();
    ////デストラクタ
    ~Stage();
    //描画以外の更新を実装する
    void Update();
    //描画に関することを実装する
    void Draw(float camera_work) const;

    bool HitStage(BoxCollider* bc);

    PLAYER_HIT_STAGE PlayerHitStage(BoxCollider* bc);
    void BreakBlock(PLAYER_HIT_STAGE phs);

};