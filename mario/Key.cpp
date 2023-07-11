#include"DxLib.h"
#include "Key.h"

Key::Key()
{
	for (int i = 0; i < KEY_NUM; i++)
	{
		key_flg[i] = { false, false };
	}

	l_stick_angle = { 0,0 };
}

void Key::Update()
{
	for (int i = 0; i < KEY_NUM; i++)
	{
		key_flg[i].old = key_flg[i].now;
		key_flg[i].now = FALSE;
	}

	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))key_flg[A].now = TRUE;//Aボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)) key_flg[B].now = TRUE;//Bボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6)) key_flg[RB].now = TRUE;//Rボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5)) key_flg[LB].now = TRUE;//Lボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8)) key_flg[START].now = TRUE;//スタートボタンが押されているか

	GetJoypadAnalogInputRight(&r_stick_angle.x, &r_stick_angle.y, DX_INPUT_PAD1); // 入力状態を取得
	GetJoypadAnalogInput(&l_stick_angle.x, &l_stick_angle.y, DX_INPUT_PAD1); // 入力状態を取得

	if (l_stick_angle.y < 0)key_flg[UP].now = TRUE;
	if (l_stick_angle.y > 0)key_flg[DOWN].now = TRUE;
	if (l_stick_angle.x < 0)key_flg[LEFT].now = TRUE;
	if (l_stick_angle.x > 0)key_flg[RIGHT].now = TRUE;
}

bool Key::KeyPressed(int key_type)//押してるとき
{
	if (key_flg[key_type].now)return TRUE;
	return FALSE;
}

bool Key::KeyUp(int key_type)//離したとき
{
	if ((!key_flg[key_type].now) && (key_flg[key_type].old))return TRUE;
	return FALSE;
}

bool Key::KeyDown(int key_type)//押した瞬間
{
	if ((!key_flg[key_type].old) && (key_flg[key_type].now))return TRUE;
	return FALSE;
}

DATA Key::GetStickAngle(int key)
{
	DATA sa = { 0,0 };

	if (key == LEFT)sa.x = l_stick_angle.x, sa.y = l_stick_angle.y;
	else if (key == RIGHT)sa.x = r_stick_angle.x, sa.y = r_stick_angle.y;

	return sa;
}
