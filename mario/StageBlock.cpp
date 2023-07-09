#include"DxLib.h"
#include"StageBlock.h"

StageBlock::StageBlock(int x, int y, int type)
{
    LoadDivGraph("image/stage_block_2.png", BLOCK_TYPE_NUM, BLOCK_TYPE_NUM, 1, STAGE_BLOCK_SIZE_X, STAGE_BLOCK_SIZE_Y, block_image);

    size = { STAGE_BLOCK_SIZE_X,STAGE_BLOCK_SIZE_Y };
    location.x = (x * size.x) + (size.x / 2);
    location.y = (y * size.y) + (size.y / 2);
    
    block_type = BLOCK_TYPE::NONE, item_type = ITEM_TYPE::NONE;
    if (type >= 12)block_type = BLOCK_TYPE::NORMAL;
    if (type >= 25)
    {
        block_type = BLOCK_TYPE::HATENA;
        if(type == 25)item_type = ITEM_TYPE::COIN;
        else if (type == 26)item_type = ITEM_TYPE::MUSHROOM;
    }
    if (type >= 29)
    {
        block_type = BLOCK_TYPE::BRICK;
        if (type == 30)item_type = ITEM_TYPE::COIN;
        else if (type == 31)item_type = ITEM_TYPE::STAR;
    }
    if (type >= 32)block_type = BLOCK_TYPE::SIDE_CLAY_PIPE;
    if (type >= 34)block_type = BLOCK_TYPE::VERTICAL_CLAY_PIPE;
    if (type == 36)block_type = BLOCK_TYPE::TRANSPARENT_BLOCK, item_type = ITEM_TYPE::ONE_UP_MUSHROOM;
  
    block_image_type = type;
    if (block_type == BLOCK_TYPE::HATENA)block_image[HATENA_BLOCK_IMAGE_FIRST];
}

void StageBlock::Update()
{

}

void StageBlock::Draw(float camera_work) const
{
    DrawRotaGraph(location.x + camera_work, location.y, 1, 0, block_image[block_image_type], TRUE, FALSE);
}

BREAK_BLOCK StageBlock::BreakBlock()
{
    BREAK_BLOCK bb = { item_type, location };

    if (block_type == BLOCK_TYPE::HATENA)
    {
        block_type = BLOCK_TYPE::NORMAL;
        block_image_type = 15;
    }
    else if (block_type == BLOCK_TYPE::BRICK)
    {
        block_type = BLOCK_TYPE::NONE;
        block_image_type = 0;
    }
    else if (block_type == BLOCK_TYPE::TRANSPARENT_BLOCK)
    {
        block_type = BLOCK_TYPE::NORMAL;
        block_image_type = 15;
    }

    

    item_type = ITEM_TYPE::NONE;

    return bb;
}