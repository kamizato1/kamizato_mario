#include"DxLib.h"
#include"Stage.h"



#define HATENA_BLOCK_IMAGE_FIRST 25
#define HATENA_BLOCK_IMAGE_LAST 28
#define HATENA_BLOCK_IMAGE_CHANGE_TIME 6


Stage::Stage()
{
	LoadDivGraph("image/stage_block_2.png", BLOCK_TYPE_NUM, BLOCK_TYPE_NUM, 1, STAGE_BLOCK_SIZE_X, STAGE_BLOCK_SIZE_Y, block_image);

	FILE* fp;//ステージ１ファイル読み込み
	fopen_s(&fp, "data/stage01.txt", "r");

	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{

			int type;
			fscanf_s(fp, "%d", &type);

			int image = block_image[type];
			if (type >= HATENA_BLOCK_IMAGE_FIRST && type <= HATENA_BLOCK_IMAGE_LAST)image = block_image[HATENA_BLOCK_IMAGE_FIRST];

			stageblock[i][j] = new StageBlock(j, i, type, image);
		}
	}
	fclose(fp);

	hatena_block_image_type = HATENA_BLOCK_IMAGE_FIRST;
	hatena_block_image_change_time = 0;
}

Stage::~Stage()
{
	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			delete  stageblock[i][j];
		}
	}
}

void Stage::Update()
{
	if (--hatena_block_image_change_time <= 0)
	{
		if (++hatena_block_image_type > HATENA_BLOCK_IMAGE_LAST)hatena_block_image_type = HATENA_BLOCK_IMAGE_FIRST;

		for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
		{
			for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
			{
				if (stageblock[i][j]->GetBlockType() == BLOCK_TYPE::HATENA)
				{
					stageblock[i][j]->ChangeBlockImage(block_image[hatena_block_image_type]);
				}
			}
		}

		if (hatena_block_image_type == HATENA_BLOCK_IMAGE_FIRST)hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME * 3;
		else hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME;
	}
}

void Stage::Draw(float camera_work) const
{
	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			stageblock[i][j]->Draw(camera_work);
		}
	}
}

bool Stage::HitStage(BoxCollider* bc)
{
	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			if (stageblock[i][j]->HitBox(bc))
			{
				if (stageblock[i][j]->GetBlockType() != BLOCK_TYPE::NONE)return TRUE;
			}
		}
	}
	return FALSE;
}

void Stage::BreakBlock(BoxCollider* bc)
{
	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			if (stageblock[i][j]->HitBox(bc))
			{
				if (stageblock[i][j]->GetBlockType() == BLOCK_TYPE::HATENA)
				{
					stageblock[i][j]->ChangeBlockImage(block_image[15]);
					stageblock[i][j]->ChangeBlockType(BLOCK_TYPE::NORMAL);
				}
				//else if()
			}
		}
	}
}