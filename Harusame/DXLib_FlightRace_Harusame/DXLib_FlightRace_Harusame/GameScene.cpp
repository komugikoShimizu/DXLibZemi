#include "GameScene.h"

namespace Scene
{
	void GameScene::Calculation()
	{
		printfDx("GameScene::Calculation\n");
	}

	void GameScene::TwoDimensionsDraw()
	{
		printfDx("GameScene::TWoDimensionsDraw\n");
	}

	void GameScene::ThreeDimensionsDraw()
	{
		printfDx("GameScene::ThreeDimensionsDraw\n");
	}

	TransitionType GameScene::GetNextState()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}