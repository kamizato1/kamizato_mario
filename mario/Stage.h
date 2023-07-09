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
    ////�f�X�g���N�^
    ~Stage();
    //�`��ȊO�̍X�V����������
    void Update();
    //�`��Ɋւ��邱�Ƃ���������
    void Draw(float camera_work) const;

    bool HitStage(BoxCollider* bc);

    PLAYER_HIT_STAGE PlayerHitStage(BoxCollider* bc);
    void BreakBlock(PLAYER_HIT_STAGE phs);

};