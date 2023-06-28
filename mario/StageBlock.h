#pragma once

#include"BoxCollider.h"
#include"define.h"

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

class StageBlock : public BoxCollider
{
private:

    int image;
    BLOCK_TYPE block_type;

public:

    StageBlock(int x, int y, int type, int image);

    //�`��ȊO�̍X�V����������
    void Update();
    //�`��Ɋւ��邱�Ƃ���������
    void Draw(float camera_work) const;

    BLOCK_TYPE GetBlockType() { return block_type; }
    void ChangeBlockType(BLOCK_TYPE type) { block_type = type; }
    void ChangeBlockImage(int image) { this->image = image; }
};