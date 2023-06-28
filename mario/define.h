#pragma once

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define KEY_NUM 10

#define STAGE_BLOCK_NUM_X 250
#define STAGE_BLOCK_NUM_Y 15

#define STAGE_BLOCK_SIZE_X 32
#define STAGE_BLOCK_SIZE_Y 32

#define GRAVITY 0.4

enum
{
    A,
    B,
    X,
    Y,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LB,
    RB
};

struct DATA //���W,�傫��,�X�s�[�h�ȂǂɎg��
{
    float x, y;
};
