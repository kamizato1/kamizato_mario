#include"DxLib.h"
#include"Stage.h"


#define HATENA_BLOCK_IMAGE_CHANGE_TIME 6

Stage::Stage()
{
	
	FILE* fp;//ステージ１ファイル読み込み
	fopen_s(&fp, "data/stage01.txt", "r");

	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{

			int type;
			fscanf_s(fp, "%d", &type);

			stageblock[i][j] = new StageBlock(j, i, type);
		}
	}
	fclose(fp);

	hatena_block_image_type = HATENA_BLOCK_IMAGE_FIRST;
	hatena_block_image_change_time = 0;

	item = nullptr;
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
	
	delete item;
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
					stageblock[i][j]->SetBlockImageType(hatena_block_image_type);
				}
			}
		}

		if (hatena_block_image_type == HATENA_BLOCK_IMAGE_FIRST)hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME * 3;
		else hatena_block_image_change_time = HATENA_BLOCK_IMAGE_CHANGE_TIME;
	}

	if(item != nullptr)item->Update(this);
}

void Stage::Draw(float camera_work) const
{
	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			if (stageblock[i][j]->GetBlockType() == BLOCK_TYPE::NONE)
			{
				stageblock[i][j]->Draw(camera_work);
			}
		}
	}

	if (item != nullptr)item->Draw(camera_work);

	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			if (stageblock[i][j]->GetBlockType() != BLOCK_TYPE::NONE)
			{
				stageblock[i][j]->Draw(camera_work);
			}
		}
	}
}

PLAYER_HIT_STAGE Stage::PlayerHitStage(BoxCollider* bc)
{
	PLAYER_HIT_STAGE phs = {0, 0, FALSE};

	for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	{
		for (int j = 0; j < STAGE_BLOCK_NUM_X; j++)
		{
			if (stageblock[i][j]->HitBox(bc))
			{
				if (stageblock[i][j]->GetBlockType() != BLOCK_TYPE::NONE)
				{
					phs = { i, j, TRUE };
					return phs;
				}
			}
		}
	}
	return phs;
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

void Stage::BreakBlock(PLAYER_HIT_STAGE phs)
{
	BREAK_BLOCK bb = stageblock[phs.y][phs.x]->BreakBlock();
	if (bb.item_type != ITEM_TYPE::NONE)item = new Item(bb.item_type, bb.location);
}


