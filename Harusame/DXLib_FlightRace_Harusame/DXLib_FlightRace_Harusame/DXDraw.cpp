#include "DXDraw.h"

DXDraw::DXDraw()
{
	// DXLib�̏���������
	DxLib_Init();
	SetMainWindowText("FlightRace");				// �E�B���h�E���̐ݒ�
	ChangeWindowMode(TRUE);							// ���\��
	SetGraphMode(640, 480, 32);						// �E�B���h�E�T�C�Y
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);	// �E�B���h�E�T�C�Y�̕ύX�̉�
	SetWaitVSyncFlag(TRUE);							// ��ʕ`��̓���
	SetDrawScreen(DX_SCREEN_BACK);					// �`�����މ�ʂ����߂�
}

DXDraw::~DXDraw()
{
	// DXLib�̏I������
	DxLib_End();
}