/********************************************************************
//���C��
********************************************************************/
#include "DxLib.h"

#include"Key.h"
#include"Title.h"
#include"GameMain.h"
#include"SceneManager.h"
#include"define.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // �^�C�g���� test �ɕύX
    SetMainWindowText(" �}���I");

    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);
    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������


    //SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    SceneManager* sceneMng = new SceneManager(new GameMain());
    Key* key = new Key();

    while (ProcessMessage() == 0)
    {
        key->Update();

        sceneMng->Update(key);

        ClearDrawScreen();		// ��ʂ̏�����

        sceneMng->Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

        sceneMng->ChangeScene();
    }


    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}