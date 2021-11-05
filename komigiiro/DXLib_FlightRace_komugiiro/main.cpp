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
	
	UIUtilty* ui = new UIUtilty();

	ui->FontSeter("PixelMplus10", "PixelMplus10-Regular",30,20);
	ui->FontSeter(40, 20);

	bool fontsize = false;
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		bool isFinish = sceneManager->SceneProcess();

		if (CheckHitKey(KEY_INPUT_A) != 0)
		{
			ui->TextCreater("テキスト表示!(A)",1,1);
		}

		if (CheckHitKey(KEY_INPUT_S) != 0)
		{
			ui->TextCreater("テキスト表示!(S)",100,100);
		}

		if (CheckHitKey(KEY_INPUT_D) != 0)
		{
			ui->TextCreater("テキスト表示!(D)", 200, 200,40);
		}

		if (CheckHitKey(KEY_INPUT_F) != 0)
		{
			ui->TextCreater("テキスト表示!(F)", 300, 300, 30);
		}

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