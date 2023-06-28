#pragma once

#include"BoxCollider.h"
#include"define.h"

enum class BLOCK_TYPE
{
    NONE, // なし
    NORMAL, //ブロック
    HATENA,
    BRICK,
    SIDE_CLAY_PIPE,
    VERTICAL_CLAY_PIPE,
    TRANSPARENT_BLOCK //透明ブロック
};

class StageBlock : public BoxCollider
{
private:

    int image;
    BLOCK_TYPE block_type;

public:

    StageBlock(int x, int y, int type, int image);

    //描画以外の更新を実装する
    void Update();
    //描画に関することを実装する
    void Draw(float camera_work) const;

    BLOCK_TYPE GetBlockType() { return block_type; }
    void ChangeBlockType(BLOCK_TYPE type) { block_type = type; }
    void ChangeBlockImage(int image) { this->image = image; }
};