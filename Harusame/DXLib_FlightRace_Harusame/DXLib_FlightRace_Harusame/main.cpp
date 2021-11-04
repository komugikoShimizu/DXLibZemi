#include <DxLib.h>
#include <Memory>
#include "DXDraw.h"
#include "SceneManager.h"
using namespace Scene;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 初期化処理、終了処理をまとめたクラスを呼び出し、上記クラスのポインタを生成する
	//DXDraw* ptrDxDraw = new DXDraw();
	// 上記のユニークポインタ版（自動でdeleteされる）
	auto ptrDxDraw = std::make_unique<DXDraw>();
	auto ptrSceneManager = std::make_unique<SceneManager>();
	char Buf[256];
	//auto draw = std::make_unique<DxDraw>();
	while (ProcessMessage() == 0)
	{
		///*演算*/
		//{
		//	GetHitKeyStateAll(Buf);
		//}
		///*描画*/
		//{
		//	//3D(主描画)
		//	{
		//	}
		//	//2D(UI:ユーザーインターフェース)
		//	{
		//		clsDx();
		//		printfDx("Buf[KEY_INPUT_Z] = %d \n", Buf[KEY_INPUT_Z]);
		//	}
		//}
		ClearDrawScreen();
		bool isFinish = ptrSceneManager->SceneProcess();
		ScreenFlip();
		//ESCキーを押すとゲームループから抜けます
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
		if (isFinish) break;
	}
	// デストラクタを呼び出すためにdeleteする（今回は自動なため省略）
	//delete ptrDxDraw;
	return 0;              // ソフトの終了 
}