#pragma once
#include "SceneBase.h"
#include <DxLib.h>

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;
	};

	GameScene::GameScene()
	{
	}

	GameScene::~GameScene()
	{
	}
}