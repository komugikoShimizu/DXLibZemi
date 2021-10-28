#include <DxLib.h>
#include <Memory>
#include "DXDraw.h"
#include "SceneManager.h"
using namespace Scene;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �����������A�I���������܂Ƃ߂��N���X���Ăяo���A��L�N���X�̃|�C���^�𐶐�����
	//DXDraw* ptrDxDraw = new DXDraw();
	// ��L�̃��j�[�N�|�C���^�Łi������delete�����j
	auto ptrDxDraw = std::make_unique<DXDraw>();
	auto ptrSceneManager = std::make_unique<SceneManager>();
	char Buf[256];
	//auto draw = std::make_unique<DxDraw>();
	while (ProcessMessage() == 0)
	{
		///*���Z*/
		//{
		//	GetHitKeyStateAll(Buf);
		//}
		///*�`��*/
		//{
		//	//3D(��`��)
		//	{
		//	}
		//	//2D(UI:���[�U�[�C���^�[�t�F�[�X)
		//	{
		//		clsDx();
		//		printfDx("Buf[KEY_INPUT_Z] = %d \n", Buf[KEY_INPUT_Z]);
		//	}
		//}
		ClearDrawScreen();
		bool isFinish = ptrSceneManager->SceneProcess();
		ScreenFlip();
		//ESC�L�[�������ƃQ�[�����[�v���甲���܂�
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
		if (isFinish) break;
	}
	// �f�X�g���N�^���Ăяo�����߂�delete����i����͎����Ȃ��ߏȗ��j
	//delete ptrDxDraw;
	return 0;              // �\�t�g�̏I�� 
}