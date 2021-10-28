#pragma once
#include "SceneBase.h"

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
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