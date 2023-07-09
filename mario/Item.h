#pragma once

#include"BoxCollider.h"
#include"Stage.h"
#include"define.h"



class Item : public BoxCollider
{
private:

    int image[6][4];
    int image_type;
    int image_type_num;
    ITEM_TYPE type;
    DATA speed;

public:

    Item(ITEM_TYPE type, DATA location);
    ////デストラクタ
    ~Item();

    //描画以外の更新を実装する
    void Update(class Stage* stage);
    //描画に関することを実装する
    void Draw(float camera_work) const;

};