#pragma once
#include "SceneBase.h"

namespace Scene {
	class GameScene :public SceneBase
	{
	public:
		GameScene();
		~GameScene();

		virtual void Calculation() override;
		virtual void TwoDimesionsDraw() override;
		virtual void ThreeDimesionsDraw() override;

	};
}