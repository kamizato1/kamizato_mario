#include"DxLib.h"
#include "Key.h"

Key::Key()
{
	for (int i = 0; i < KEY_NUM; i++)
	{
		key_flg[i] = { false, false };
	}
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
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8)) key_flg[START].now = TRUE;//スタートボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP))key_flg[UP].now = TRUE;//UPボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN))key_flg[DOWN].now = TRUE;//DOWNボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT))key_flg[LEFT].now = TRUE;//LEFTボタンが押されているか
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT))key_flg[RIGHT].now = TRUE;//RIGHTボタンが押されているか
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
