#pragma once
#include "SceneBase.hpp"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();
		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;
	};

	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}
}



