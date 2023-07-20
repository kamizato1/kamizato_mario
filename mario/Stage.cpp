#include"DxLib.h"
#include"Stage.h"



#define HATENA_BLOCK_IMAGE_CHANGE_TIME 8

Stage::Stage()
{
	int block_image[BLOCK_TYPE_NUM];
	LoadDivGraph("image/stage_block_2.png", BLOCK_TYPE_NUM, BLOCK_TYPE_NUM, 1, STAGE_BLOCK_SIZE_X, STAGE_BLOCK_SIZE_Y, block_image);
	sky_image = LoadGraph("image/sky.png");
	sky_image = LoadGraph("image/sky.png");
	for (int i = 0; i < STAGE_BLOCK_NUM; i++)stageblock[i] = nullptr;
	
	FILE* fp;//ステージ１ファイル読み込み
	fopen_s(&fp, "data/stage01.txt", "r");

	int back_ground_count = 0;
	int stage_block_count = 0;

	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			int type;
			fscanf_s(fp, "%d", &type);

			if (type <= 11)
			{
				if (back_ground_count < BACK_GROUND_NUM && type > 0)
				{
					back_ground[back_ground_count].location.x = (j * STAGE_BLOCK_SIZE_X);
					back_ground[back_ground_count].location.y = (i * STAGE_BLOCK_SIZE_Y);
					back_ground[back_ground_count].image = block_image[type];
					back_ground_count++;
				}
			}
			else if(stage_block_count < STAGE_BLOCK_NUM)
			{
				stageblock[stage_block_count] = new StageBlock(j, i, type);
				stage_block_count++;
			}
		}
	}
	fclose(fp);

	hatena_block_image_type = HATENA_BLOCK_IMAGE_FIRST;
	hatena_block_image_change_time = 0;

	item = nullptr;
}

Stage::~Stage()
{
	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		delete  stageblock[i];
	}
	delete item;
}

void Stage::Update()
{
	if (--hatena_block_image_change_time <= 0)
	{
		if (++hatena_block_image_type > HATENA_BLOCK_IMAGE_LAST)hatena_block_image_type = HATENA_BLOCK_IMAGE_FIRST;

		for (int i = 0; i < STAGE_BLOCK_NUM; i++)
		{
			if (stageblock[i] != nullptr)
			{
				if (stageblock[i]->GetBlockType() == BLOCK_TYPE::HATENA)
				{
					stageblock[i]->SetBlockImageType(hatena_block_image_type);
				}
				
			}
		}


		if (hatena_block_image_type == HATENA_BLOCK_IMAGE_FIRST)hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME * 3;
		else hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME;
	}

	

	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		if (stageblock[i] != nullptr)
		{
			stageblock[i]->Update(this);
		}
	}
	
	if (item != nullptr)item->Update(this);
}

void Stage::Draw(float camera_work) const
{
	DrawGraph(0, 0, sky_image, FALSE);
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		DrawGraph(back_ground[i].location.x + camera_work, back_ground[i].location.y, back_ground[i].image, FALSE);
	}
	//DrawBackGround(camera_work);
	if (item != nullptr)item->Draw(camera_work);
	//DrawStage(camera_work);

	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		if (stageblock[i] != nullptr)
		{
			stageblock[i]->Draw(camera_work);
		}
	}
}

void Stage::DrawBackGround(float camera_work)const
{
	DrawGraph(0, 0, sky_image, FALSE);
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		DrawGraph(back_ground[i].location.x + camera_work, back_ground[i].location.y, back_ground[i].image, FALSE);
	}
}

void Stage::DrawStage(float camera_work)const
{
	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		if (stageblock[i] != nullptr)
		{
			stageblock[i]->Draw(camera_work);
		}
	}
}

PLAYER_HIT_STAGE Stage::PlayerHitStage(BoxCollider* bc)
{
	PLAYER_HIT_STAGE player_hit_stage = {0, FALSE};

	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		if (stageblock[i] != nullptr)
		{
			if (stageblock[i]->HitBox(bc))
			{
				player_hit_stage = { i, TRUE };
				return player_hit_stage;
			}
		}
	}
	return player_hit_stage;
}

bool Stage::HitStage(BoxCollider* bc)
{
	for (int i = 0; i < STAGE_BLOCK_NUM; i++)
	{
		if (stageblock[i] != nullptr)
		{
			if (stageblock[i]->HitBox(bc))return TRUE;
		}
	}
	return FALSE;
}

void Stage::BreakBlock(int block_num)
{
	if (stageblock[block_num]->BreakBlock())
	{
		stageblock[block_num] = nullptr;
	}
	//if (break_block.item_type != ITEM_TYPE::NONE)item = new Item(break_block.item_type, break_block.location);
}

void Stage::ItemGeneration(DATA location, ITEM_TYPE type)
{
	item = new Item(type,location);
}
