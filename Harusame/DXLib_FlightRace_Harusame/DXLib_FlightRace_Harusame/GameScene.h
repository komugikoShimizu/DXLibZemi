#pragma once
#include "SceneBase.h"

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase を介して継承されました
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;

	};

	GameScene::GameScene()
	{
	}

	GameScene::~GameScene()
	{
	}
}