#pragma once

#include <DxLib.h>
#include <vector>
#include <Effekseer.h>
#include "EffekseerEffectHandle.hpp"
#include "SceneBase.hpp"
#include "Effect.hpp"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();
		// SceneBase ÇâÓÇµÇƒåpè≥Ç≥ÇÍÇ‹ÇµÇΩ
		virtual void Calculation(SetDrawCameraInfo&) override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;
		TransitionType GetNextState() override;
	private:
		
	};

	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}
}



