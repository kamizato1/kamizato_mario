#include"DxLib.h"
#include"GameMain.h"

GameMain::GameMain()
{
    stage = new Stage();
    key = new Key();
    player = new Player();

    stop = FALSE;
}

GameMain::~GameMain()
{
    delete stage;
    delete key;
    delete player;
}

void GameMain::Update(Key* key)
{
    key->Update();

    if (!stop)
    {
        player->Update(key, stage);
        stage->Update();
    }
    if(key->KeyPressed(A))stop = !stop;
}

void GameMain::Draw() const
{
    float camera_work = 0;
    if(player->GetLocation().x >= 200)camera_work = -player->GetLocation().x + 200;

    stage->Draw(camera_work);
    player->Draw(camera_work);
}

AbstractScene* GameMain::ChangeScene()
{
    return this;
}