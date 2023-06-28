#pragma once
#include"AbstractScene.h"
#include"Key.h"

class SceneManager
{
private:
	AbstractScene* mScene;  //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManager(AbstractScene* scene);

	//�f�X�g���N�^
	/*~SceneManager()
	{
		delete mScene;
	}*/

	//�`��ȊO�̍X�V����������
	void Update(Key* key);

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const;

	void ChangeScene();
};