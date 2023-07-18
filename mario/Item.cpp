#include <math.h>
#include"DxLib.h"
#include"Item.h"

#define ITEM_SIZE_X 20
#define ITEM_SIZE_Y 32

#define ITEM_SPEED 2

Item::Item(ITEM_TYPE type, DATA location)
{
	this->type = type;
	this->location = location;
	size = { ITEM_SIZE_X, ITEM_SIZE_Y };

	int image[24];
	LoadDivGraph("image/Item/item.png", 24, 4, 6, 32, 32, image);
	int count = 0;
	for (int i = 0; i < 6; i++)for (int j = 0; j < 4; j++)this->image[i][j] = image[count], count++;
	
	image_type = static_cast<int>(type);
	image_type_num = 0;
	speed = { ITEM_SPEED, ITEM_SPEED };
}

Item::~Item()
{

}

void Item::Update(Stage* stage)
{
	if (stage->HitStage(this))location.y -= 1;
	else
	{
		//yÀ•W‚ÌˆÚ“®«
		if (speed.y >= 0)speed.y += GRAVITY * 2;
		else speed.y += GRAVITY;
		if (speed.y > MAX_GRAVITY)speed.y = MAX_GRAVITY;
		location.y += speed.y;

		if (stage->HitStage(this))//áŠQ•¨‚É“–‚½‚Á‚Ä‚¢‚é‚Æ‚«
		{
			location.y = floor(location.y);
			float sign = -(speed.y / fabsf(speed.y));
			while (stage->HitStage(this))location.y += sign;
			speed.y = 0;
		}

		location.x += speed.x;
		if (stage->HitStage(this))//áŠQ•¨‚É“–‚½‚Á‚Ä‚¢‚é‚Æ‚«
		{
			location.x = floor(location.x);
			float sign = -(speed.x / fabsf(speed.x));
			while (stage->HitStage(this))location.x += sign;
			speed.x = -speed.x;
		}
	}
}

void Item::Draw(float camera_work) const
{
	DrawRotaGraph(location.x + camera_work, location.y, 1, 0, image[image_type][0], TRUE, FALSE);
}