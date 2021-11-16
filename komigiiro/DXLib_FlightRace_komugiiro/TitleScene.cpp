#include "TitleScene.h"
#include "DxLib.h"
 
namespace Scene
{
	int num = 30;
	double pos = 1;
	bool flg = true;
	void TitleScene::Calculation()
	{
		// printfDx("TitleScene::Calculation\n");
	}

	void TitleScene::TwoDimentionsDraw()
	{
		num++;
		pos++;
		if (pos > 50) pos = -10;
		if (num % 30 == 0) flg = flg ? false : true;
		ui->TextCreater("ゲームプログラミング　制作", CanvasSize{pos,0}, 20, "black","white",true);
		ui->TextCreater("DXLib FlightRace!!", CanvasSize{8,15}, 50, "red", "blue", false);
	    if (flg) ui->TextCreater("Press Enter Key - GameStart!", CanvasSize{15,35}, 20, "white");
		ui->TextCreater("Esc - GameExit", CanvasSize{40,50}, 20, "white");
	}

	void TitleScene::ThreeDimensionsDraw()
	{
		// printfDx("TitleScene::ThreeDimensionsDraw");
	}

	TransitionType TitleScene::GetNextScene()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}