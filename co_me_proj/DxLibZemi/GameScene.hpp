#pragma once
#include "SceneBase.hpp"

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
	private:
	};

	GameScene::GameScene()
	{
	}

	GameScene::~GameScene()
	{
	}
}


