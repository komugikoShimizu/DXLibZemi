#pragma once
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();

		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;
	private:
	};

	ResultScene::ResultScene()
	{
	}

	ResultScene::~ResultScene()
	{
	}
}