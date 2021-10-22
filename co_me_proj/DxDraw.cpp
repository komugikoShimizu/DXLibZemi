#include"DxDraw.hpp"
#include<DxLib.h>

DxDraw::DxDraw()
{
	SetOutApplicationLogValidFlag(FALSE);           /*log*/
	SetMainWindowText("game title");                /*タイトル*/
	ChangeWindowMode(TRUE);                         /*窓表示*/
	SetUseDirect3DVersion(DX_DIRECT3D_11);          /*directX ver*/
	SetGraphMode(640, 480, 32);                     /*解像度*/
	SetUseDirectInputFlag(TRUE);                    /*DirectInput使用*/
	SetDirectInputMouseMode(TRUE);                  /*DirectInputマウス使用*/
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);    /*ウインドウサイズを手動変更不可、ウインドウサイズに合わせて拡大もしないようにする*/
	SetUsePixelLighting(TRUE);                      /*ピクセルライティングの使用*/
	SetFullSceneAntiAliasingMode(4, 2);             /*アンチエイリアス*/
	SetEnableXAudioFlag(TRUE);                      /*XAudioを用いるか*/
	Set3DSoundOneMetre(1.0f);                       /*3Dオーディオの基準距離指定*/
	SetWaitVSyncFlag(TRUE);                         /*垂直同期*/
	DxLib_Init();                                   /*ＤＸライブラリ初期化処理*/
	SetDrawScreen(DX_SCREEN_BACK);					/*裏画面に書き込み*/
	SetSysCommandOffFlag(TRUE);                     /*タスクスイッチを有効にするかどうかを設定する*/
	SetAlwaysRunFlag(TRUE);                         /*background*/
	SetUseZBuffer3D(TRUE);                          /*zbufuse*/
	SetWriteZBuffer3D(TRUE);                        /*zbufwrite*/
	MV1SetLoadModelPhysicsWorldGravity(-9.8f);      /*重力*/
}

DxDraw::~DxDraw()
{
	DxLib_End();
}