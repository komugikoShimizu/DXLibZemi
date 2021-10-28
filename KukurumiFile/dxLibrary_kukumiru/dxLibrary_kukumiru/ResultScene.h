#pragma once
#include "SceneBase.h"

namespace Scene {
	class ResultScene :public SceneBase
	{
	public:
		ResultScene();
		~ResultScene();

		virtual void Calculation() override;
		virtual void TwoDimesionsDraw() override;
		virtual void ThreeDimesionsDraw() override;
	};
}