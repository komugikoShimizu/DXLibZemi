#pragma once
#include "SceneBase.h"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();

		// SceneBase ����Čp������܂���
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

	private:
	};

	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}
}