#pragma once
#include "SceneBase.h"

namespace Scene {
	class TitleScene :public SceneBase
	{
	public:
		TitleScene();
		~TitleScene();

		//SceneBase����Čp������܂����B
		virtual void Calculation() override;
		virtual void TwoDimesionsDraw() override;
		virtual void ThreeDimesionsDraw() override;
	};
}