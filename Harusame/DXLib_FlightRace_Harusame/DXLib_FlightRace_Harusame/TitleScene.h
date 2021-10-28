#pragma once
namespace Scene
{
#include "SceneBase.h"
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();

		// SceneBase を介して継承されました
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
	};

	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}
}