#pragma once
#include "define.h"

struct KEY
{
	bool now;
	bool old;
};

class Key //キーの更新処理
{
private:

	KEY key_flg[KEY_NUM];

public:

	Key();//コンストラクタ
	void Update();
	bool KeyPressed(int key_type);//押してるとき
	bool KeyUp(int key_type);//離したとき
	bool KeyDown(int key_type);//押した瞬間
};