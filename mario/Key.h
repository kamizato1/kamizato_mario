#pragma once
#include "define.h"

struct KEY
{
	bool now;
	bool old;
};

class Key //�L�[�̍X�V����
{
private:

	KEY key_flg[KEY_NUM];

public:

	Key();//�R���X�g���N�^
	void Update();
	bool KeyPressed(int key_type);//�����Ă�Ƃ�
	bool KeyUp(int key_type);//�������Ƃ�
	bool KeyDown(int key_type);//�������u��
};