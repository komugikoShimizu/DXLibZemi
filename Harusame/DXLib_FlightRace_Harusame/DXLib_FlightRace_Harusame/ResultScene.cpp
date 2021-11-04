#include "ResultScene.h"

namespace Scene
{
	void ResultScene::Calculation()
	{
		printfDx("ResultScene::Calculation\n");
	}

	void ResultScene::TwoDimensionsDraw()
	{
		printfDx("ResultScene::TwoDimensionsDraw\n");
	}

	void ResultScene::ThreeDimensionsDraw()
	{
		printfDx("ResultScene::ThreeDimensionsDraw\n");
	}

	TransitionType ResultScene::GetNextState()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}