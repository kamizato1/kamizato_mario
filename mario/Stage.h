#pragma once

#include"StageBlock.h"
#include"BoxCollider.h"
#include"define.h"

#define BLOCK_TYPE_NUM 37

class Stage
{
private:

    StageBlock* stageblock[STAGE_BLOCK_NUM_Y][STAGE_BLOCK_NUM_X];
    int block_image[BLOCK_TYPE_NUM];
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
    void BreakBlock(BoxCollider* bc);
};