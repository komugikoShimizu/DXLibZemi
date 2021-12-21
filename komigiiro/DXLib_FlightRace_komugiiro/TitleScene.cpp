#include "TitleScene.h"
#include "DxLib.h"
#include "InputManager.h"
 
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
		UIUtilty::TextCreater("ゲームプログラミング　制作", CanvasPosition{pos,0}, 20, "black","white",true);
		UIUtilty::TextCreater("DXLib FlightRace!!", CanvasPosition{8,15}, 50, "red", "blue", false);
	    if (flg) UIUtilty::TextCreater("Press LeftMouse Click - GameStart!", CanvasPosition{13,35}, 20, "white");
		UIUtilty::TextCreater("Esc - GameExit", CanvasPosition{40,50}, 20, "white");
	}

	void TitleScene::ThreeDimensionsDraw()
	{
		// printfDx("TitleScene::ThreeDimensionsDraw");
	}

	TransitionType TitleScene::GetNextScene()
	{
		if (Input::isInputDown(Input::InputType::ADVANCE)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}