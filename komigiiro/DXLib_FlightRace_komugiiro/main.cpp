#include <DxLib.h>
#include <Memory>
#include "DXDraw.h"
#include "SceneManager.h"
#include "UIUtilty.h"

using namespace UI;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char Buf[256];
	//DXDraw dxDraw = DXDraw();
	//DXDraw* ptrDraw = &dxDraw;
	DXDraw* ptrDxDraw = new DXDraw();

	auto draw = std::make_unique<DXDraw>();
	auto sceneManager = std::make_unique<Scene::SceneManager>();
	
	bool fontsize = false;
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		bool isFinish = sceneManager->SceneProcess();

		ScreenFlip();

		//ESCキーを押すとゲームループから抜けます
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
		{
			break;
		}

		if (isFinish) break;
	}

	return 0;              // ソフトの終了 
}