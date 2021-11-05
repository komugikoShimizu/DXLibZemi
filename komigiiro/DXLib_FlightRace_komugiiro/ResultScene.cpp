#include "ResultScene.h"

namespace Scene
{
	void ResultScene::Calculation()
	{
		printfDx("ResultScene::Calculation\n");
	}

	void ResultScene::TwoDimentionsDraw()
	{
		printfDx("ResultScene::TwoDimentionsDraw\n");
	}

	void ResultScene::ThreeDimensionsDraw()
	{
		printfDx("ResultScene::ThreeDimensionsDraw\n");
	}

	TransitionType ResultScene::GetNextScene()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}
