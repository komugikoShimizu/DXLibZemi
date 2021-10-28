#pragma once
#include "SceneBase.h"

namespace Scene {
	class TitleScene :public SceneBase
	{
	public:
		TitleScene();
		~TitleScene();

		//SceneBaseを介して継承されました。
		virtual void Calculation() override;
		virtual void TwoDimesionsDraw() override;
		virtual void ThreeDimesionsDraw() override;
	};
}