#include"DxLib.h"
#include"StageBlock.h"

StageBlock::StageBlock(int x, int y, int type, int image)
{
    size = { STAGE_BLOCK_SIZE_X,STAGE_BLOCK_SIZE_Y };
    location.x = (x * size.x) + (size.x / 2);
    location.y = (y * size.y) + (size.y / 2);

    if (type <= 11)block_type = BLOCK_TYPE::NONE;
    else if (type <= 24)block_type = BLOCK_TYPE::NORMAL;
    else if (type <= 28)block_type = BLOCK_TYPE::HATENA;
    else if (type <= 31)block_type = BLOCK_TYPE::BRICK;
    else if (type <= 33)block_type = BLOCK_TYPE::SIDE_CLAY_PIPE;
    else if (type <= 35)block_type = BLOCK_TYPE::VERTICAL_CLAY_PIPE;
    else block_type = BLOCK_TYPE::TRANSPARENT_BLOCK;
  
    this->image = image;
}

void StageBlock::Update()
{

}

void StageBlock::Draw(float camera_work) const
{
    DrawRotaGraph(location.x + camera_work, location.y, 1, 0, image, TRUE, FALSE);
}