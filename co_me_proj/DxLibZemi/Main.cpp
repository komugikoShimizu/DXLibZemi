#include <DxLib.h>
#include <Memory>
#include "DxDraw.hpp"
#include "SceneManager.hpp"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto draw = std::make_unique<DxDraw>();
	auto sceneManager = std::make_unique<Scene::SceneManager>();

	while (ProcessMessage() == 0)
	{
		// ウィンドウの描画初期化
		ClearDrawScreen();
		// シーンマネージャー経由で現在アクティブなシーンの処理をする
		bool isFinish = sceneManager->SceneProcess();
		// 画面の描画
		ScreenFlip();

		if (isFinish)break;
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
	}

	return 0;              // ソフトの終了 
}

