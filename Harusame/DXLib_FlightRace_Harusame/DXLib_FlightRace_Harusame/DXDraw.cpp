#include "DXDraw.h"

DXDraw::DXDraw()
{
	// DXLibの初期化処理
	DxLib_Init();
	SetMainWindowText("FlightRace");				// ウィンドウ名の設定
	ChangeWindowMode(TRUE);							// 窓表示
	SetGraphMode(640, 480, 32);						// ウィンドウサイズ
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);	// ウィンドウサイズの変更の可否
	SetWaitVSyncFlag(TRUE);							// 画面描画の同期
	SetDrawScreen(DX_SCREEN_BACK);					// 描き込む画面を決める
}

DXDraw::~DXDraw()
{
	// DXLibの終了処理
	DxLib_End();
}