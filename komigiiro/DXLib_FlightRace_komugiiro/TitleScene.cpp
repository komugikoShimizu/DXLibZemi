#include "TitleScene.h"
#include "DxLib.h"
 
namespace Scene
{
	void TitleScene::Calculation()
	{
		// printfDx("TitleScene::Calculation\n");
	}

	void TitleScene::TwoDimentionsDraw()
	{
		ui->TextCreater("ゲームプログラミング　制作",0,0,20,"white");
		ui->TextCreater("DXLib FlightRace!!", 100, 100, 50, "red","blue",false);
		ui->TextCreater("Press Enter Key - GameStrat!", 200, 300, 20, "white");
		ui->TextCreater("Esc - GameExit",450,450,20,"white");
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