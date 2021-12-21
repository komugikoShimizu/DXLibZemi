#include "ResultScene.h"

namespace Scene
{
	void ResultScene::Calculation()
	{
		UIUtilty::TextCreater("GAME OVER", CanvasPosition{20,15},30,"red");
		UIUtilty::TextCreater("right click - TitleScene", CanvasPosition{ 10,25 }, 40, "blue", "green", true);
		UIUtilty::TextCreater("Esc - GameExit", CanvasPosition{ 40,50 }, 20, "white");
	}

	void ResultScene::TwoDimentionsDraw()
	{

	}

	void ResultScene::ThreeDimensionsDraw()
	{

	}

	TransitionType ResultScene::GetNextScene()
	{
		if (Input::isBackDown()) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}
