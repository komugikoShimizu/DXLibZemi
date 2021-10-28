#include <DxLib.h>
#include <Memory>
#include "DxDraw.hpp"
#include "SceneManager.hpp"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto draw = std::make_unique<DxDraw>();
	auto sceneManager = std::make_unique<Scene::SceneManager>();

	while (ProcessMessage() == 0)
	{
		// �E�B���h�E�̕`�揉����
		ClearDrawScreen();
		// �V�[���}�l�[�W���[�o�R�Ō��݃A�N�e�B�u�ȃV�[���̏���������
		bool isFinish = sceneManager->SceneProcess();
		// ��ʂ̕`��
		ScreenFlip();

		if (isFinish)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	return 0;              // �\�t�g�̏I�� 
}

