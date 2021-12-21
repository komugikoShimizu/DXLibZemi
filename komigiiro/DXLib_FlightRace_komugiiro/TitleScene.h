#pragma once
#include "SceneBase.h"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();

		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;

	private:
	};

	TitleScene::TitleScene()
	{
		UIUtilty::ColorCreater();
		UIUtilty::CanvasSizeCreate(50);
		UIUtilty::FontSeter(50);
		UIUtilty::FontSeter(40);
		UIUtilty::FontSeter(30);
		UIUtilty::FontSeter(20);
		UIUtilty::FontSeter(10);
	}

	TitleScene::~TitleScene()
	{
	}
}