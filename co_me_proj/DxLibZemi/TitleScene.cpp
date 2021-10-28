#include "TitleScene.hpp"
#include "DxLib.h"

namespace Scene
{
	void TitleScene::Calculation()
	{
		printfDx("TitleScene::Calculation\n");
	}

	void TitleScene::TwoDimensionsDraw()
	{
		printfDx("TitleScene::TwoDimensionsDraw\n");
	}

	void TitleScene::ThreeDimensionsDraw()
	{
		printfDx("TitleScene::ThreeDimensionsDraw\n");
	}

	TransitionType TitleScene::GetNextState()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}
