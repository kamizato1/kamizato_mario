#include"DxLib.h"
#include"GameMain.h"

GameMain::GameMain()
{
    stage = new Stage();
    player = new Player();
    stop = FALSE;
}

GameMain::~GameMain()
{
    delete stage;
    delete player;

}

void GameMain::Update(Key* key)
{
    if (!stop)
    {
        player->Update(key, stage);
        stage->Update();
    }
    if(key->KeyDown(A))stop = !stop;
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
