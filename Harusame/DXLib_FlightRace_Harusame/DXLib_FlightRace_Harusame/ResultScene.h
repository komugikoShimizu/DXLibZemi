#pragma once
#include "SceneBase.h"
#include <DxLib.h>

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();

		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;
	};

	ResultScene::ResultScene()
	{
	}

	ResultScene::~ResultScene()
	{
	}
}