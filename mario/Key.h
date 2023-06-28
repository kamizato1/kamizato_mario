#pragma once
#include "define.h"

struct KEY
{
	bool flg;
};

struct STICK_ANGLE
{
	int x, y;
};

class Key //�L�[�̍X�V����
{
private:

	int a;

	KEY now_key[KEY_NUM];
	KEY old_key[KEY_NUM];

	STICK_ANGLE l_stick_angle;
	STICK_ANGLE r_stick_angle;

public:

	Key();//�R���X�g���N�^

	void Update();
	bool KeyPressed(int key_type);//�����Ă�Ƃ�
	bool KeyUp(int key_type);//�������Ƃ�
	bool KeyDown(int key_type);//�������u��

	DATA GetStickAngle(int key);
};