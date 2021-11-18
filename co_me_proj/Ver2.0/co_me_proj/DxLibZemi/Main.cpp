#include <DxLib.h>
#include <Memory>
#include "DxLib.h"
#include "DxDraw.hpp"
#include "SceneManager.hpp"
#include <functional>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ゲーム全体で必要なクラス生成
	auto draw = std::make_unique<DxDraw>();
	auto sceneManager = std::make_unique<Scene::SceneManager>();
	
	while (ProcessMessage() == 0)
	{
		//ClearDrawScreen();
		// シーンマネージャー経由で現在アクティブなシーンの処理をする
		bool isFinish = sceneManager->SceneProcess();
		if (isFinish)break;
	}

	return 0;              // ソフトの終了 
}