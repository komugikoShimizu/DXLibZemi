#pragma once
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	class GameScene : public SceneBase
	{
	public:
		inline GameScene();
		inline ~GameScene();

		// SceneBase を介して継承されました
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;
	private:
	};

	GameScene::GameScene()
	{
	}

	GameScene::~GameScene()
	{
	}
}