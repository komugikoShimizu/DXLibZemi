#pragma once
#include "SceneBase.hpp"

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
	private:
	};

	ResultScene::ResultScene()
	{
	}

	ResultScene::~ResultScene()
	{
	}
}
