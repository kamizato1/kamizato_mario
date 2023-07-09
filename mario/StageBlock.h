#pragma once

#include"BoxCollider.h"
#include"define.h"
#include"Item.h"

#define BLOCK_TYPE_NUM 37
#define HATENA_BLOCK_IMAGE_FIRST 25
#define HATENA_BLOCK_IMAGE_LAST 28

enum class BLOCK_TYPE
{
    NONE, // �Ȃ�
    NORMAL, //�u���b�N
    HATENA,
    BRICK,
    SIDE_CLAY_PIPE,
    VERTICAL_CLAY_PIPE,
    TRANSPARENT_BLOCK //�����u���b�N
};

struct BREAK_BLOCK
{
    ITEM_TYPE item_type;
    DATA location;
};

class StageBlock : public BoxCollider
{
private:

    int block_image[BLOCK_TYPE_NUM];
    int block_image_type;

    BLOCK_TYPE block_type;
    ITEM_TYPE item_type;

public:

    StageBlock(int x, int y, int type);

    //�`��ȊO�̍X�V����������
    void Update();
    //�`��Ɋւ��邱�Ƃ���������
    void Draw(float camera_work) const;

    BLOCK_TYPE GetBlockType() { return block_type; }
    void SetBlockType(BLOCK_TYPE type) { block_type = type; }

    void SetBlockImageType(int block_image_type) { this->block_image_type = block_image_type; }
    int GetBlockImageType() { return block_image_type; }

    BREAK_BLOCK BreakBlock();
};