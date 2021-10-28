#pragma once
#include "SceneBase.h"

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();

		// SceneBase を介して継承されました
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;
	private:
	};

	ResultScene::ResultScene()
	{
	}

	ResultScene::~ResultScene()
	{
	}
}