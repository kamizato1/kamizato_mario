#pragma once

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define KEY_NUM 7

#define STAGE_BLOCK_NUM_X 250
#define STAGE_BLOCK_NUM_Y 15

#define STAGE_BLOCK_SIZE_X 32
#define STAGE_BLOCK_SIZE_Y 32

#define MAX_GRAVITY 8
#define GRAVITY 0.3

enum
{
    A,
    B,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    START
};

struct DATA //���W,�傫��,�X�s�[�h�ȂǂɎg��
{
    float x, y;
};

enum class ITEM_TYPE
{
    MUSHROOM,//�X�[�p�[�L�m�R
    FLOUR,//�t�@�C�A�[�t�����[
    STAR,
    COIN,//�R�C��
    IN_COIN, //�u���b�N�̒��̃R�C��
    ONE_UP_MUSHROOM, //1UP�L�m�R
    NONE,//�Ȃ�
};