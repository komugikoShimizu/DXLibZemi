#include <DxLib.h>
#include <Memory>
#include "DxLib.h"
#include "DxDraw.hpp"
#include "SceneManager.hpp"
#include <functional>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �Q�[���S�̂ŕK�v�ȃN���X����
	auto draw = std::make_unique<DxDraw>();
	auto sceneManager = std::make_unique<Scene::SceneManager>();
	
	while (ProcessMessage() == 0)
	{
		//ClearDrawScreen();
		// �V�[���}�l�[�W���[�o�R�Ō��݃A�N�e�B�u�ȃV�[���̏���������
		bool isFinish = sceneManager->SceneProcess();
		if (isFinish)break;
	}

	return 0;              // �\�t�g�̏I�� 
}