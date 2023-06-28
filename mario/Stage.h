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
    ////�f�X�g���N�^
    ~Stage();
    //�`��ȊO�̍X�V����������
    void Update();
    //�`��Ɋւ��邱�Ƃ���������
    void Draw(float camera_work) const;

    bool HitStage(BoxCollider* bc);
    void BreakBlock(BoxCollider* bc);
};