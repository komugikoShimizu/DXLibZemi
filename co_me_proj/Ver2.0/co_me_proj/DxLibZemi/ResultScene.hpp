#pragma once
#include <DxLib.h>
#include "SceneBase.hpp"

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();
		// SceneBase を介して継承されました
		virtual void Calculation(SetDrawCameraInfo&) override;
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
