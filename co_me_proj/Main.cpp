#include <DxLib.h>
#include <Memory>
#include "DxDraw.hpp"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char Buf[256];
	auto draw = std::make_unique<DxDraw>();
	while (ProcessMessage() == 0)
	{
		/*���Z*/
		{
			GetHitKeyStateAll(Buf);
		}
		/*�`��*/
		{
			//3D(��`��)
			{
			}
			//2D(UI:���[�U�[�C���^�[�t�F�[�X)
			{
				clsDx();
				printfDx("Buf[KEY_INPUT_Z] = %d \n", Buf[KEY_INPUT_Z]);
			}
		}
		ScreenFlip();
		//ESC�L�[�������ƃQ�[�����[�v���甲���܂�
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
	}

	return 0;              // �\�t�g�̏I�� 
}