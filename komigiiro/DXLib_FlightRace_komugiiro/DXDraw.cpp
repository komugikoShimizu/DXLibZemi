#include "DXDraw.h"
#include <DxLib.h>

DXDraw::DXDraw()
{
	DxLib_Init(); // ウィンドウ作成、DXLib起動
	SetMainWindowText("Flight_komigi"); // ウィンドウ名
	SetGraphMode(640, 480, 32); // ウィンドウサイズ
	SetWindowSizeChangeEnableFlag(FALSE, FALSE); // 
	SetWaitVSyncFlag(TRUE); // 
	SetDrawScreen(DX_SCREEN_BACK); // 書き込む画面

}

DXDraw::~DXDraw()
{
	DxLib_End();
}