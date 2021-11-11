#include "GameScene.h"

namespace Scene
{
	void GameScene::Calculation()
	{
		printfDx("GameScene::Calculation\n");
	}

	void GameScene::TwoDimentionsDraw()
	{
		printfDx("GameScene::TwoDimentionsDraw\n");
	}

	void GameScene::ThreeDimensionsDraw()
	{
		printfDx("GameScene::ThreeDimensionsDraw\n");
	}

	TransitionType GameScene::GetNextScene()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}
