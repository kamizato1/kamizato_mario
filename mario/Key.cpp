#include"DxLib.h"
#include "Key.h"

Key::Key()
{
	for (int i = 0; i < KEY_NUM; i++)
	{
		now_key[i].flg = false;
		old_key[i].flg = false;
	}

	l_stick_angle = { 0,0 };
}

void Key::Update()
{
	for (int i = 0; i < KEY_NUM; i++)
	{
		old_key[i].flg = now_key[i].flg;
	}

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))now_key[A].flg = TRUE;//A�{�^����������Ă��邩
	else now_key[A].flg = FALSE;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) now_key[B].flg = TRUE;//B�{�^����������Ă��邩
	else  now_key[B].flg = FALSE;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6)) now_key[RB].flg = TRUE;//R�{�^����������Ă��邩
	else  now_key[RB].flg = FALSE;
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5)) now_key[LB].flg = TRUE;//L�{�^����������Ă��邩
	else  now_key[LB].flg = FALSE;


	GetJoypadAnalogInputRight(&r_stick_angle.x, &r_stick_angle.y, DX_INPUT_PAD1); // ���͏�Ԃ��擾
	GetJoypadAnalogInput(&l_stick_angle.x, &l_stick_angle.y, DX_INPUT_PAD1); // ���͏�Ԃ��擾
	if (l_stick_angle.y < 0)now_key[UP].flg = TRUE; else now_key[UP].flg = FALSE;
	if (l_stick_angle.y > 0)now_key[DOWN].flg = TRUE; else now_key[DOWN].flg = FALSE;
	if (l_stick_angle.x < 0)now_key[LEFT].flg = TRUE; else now_key[LEFT].flg = FALSE;
	if (l_stick_angle.x > 0)now_key[RIGHT].flg = TRUE; else now_key[RIGHT].flg = FALSE;
}

bool Key::KeyPressed(int key_type)//�����Ă�Ƃ�
{
	if (now_key[key_type].flg)return TRUE;
	else return FALSE;
}

bool Key::KeyUp(int key_type)//�������Ƃ�
{
	if ((!now_key[key_type].flg) && (old_key[key_type].flg))return TRUE;
	else return FALSE;
}

bool Key::KeyDown(int key_type)//�������u��
{
	if ((!old_key[key_type].flg) && (now_key[key_type].flg))return TRUE;
	else return FALSE;
}

DATA Key::GetStickAngle(int key)
{
	DATA sa = { 0,0 };

	if (key == LEFT)sa.x = l_stick_angle.x, sa.y = l_stick_angle.y;
	else if (key == RIGHT)sa.x = r_stick_angle.x, sa.y = r_stick_angle.y;

	return sa;
}