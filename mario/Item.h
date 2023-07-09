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
    ////�f�X�g���N�^
    ~Item();

    //�`��ȊO�̍X�V����������
    void Update(class Stage* stage);
    //�`��Ɋւ��邱�Ƃ���������
    void Draw(float camera_work) const;

};