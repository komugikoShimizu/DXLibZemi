#include "DXDraw.h"
#include <DxLib.h>

DXDraw::DXDraw()
{
	SetMainWindowText("Flight_komigi"); // �E�B���h�E��
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32); // �E�B���h�E�T�C�Y
	SetWindowSizeChangeEnableFlag(FALSE, FALSE); // 
	SetWaitVSyncFlag(TRUE); // 
	DxLib_Init(); // �E�B���h�E�쐬�ADXLib�N��
	SetDrawScreen(DX_SCREEN_BACK); // �������މ��

}

DXDraw::~DXDraw()
{
	DxLib_End();
}