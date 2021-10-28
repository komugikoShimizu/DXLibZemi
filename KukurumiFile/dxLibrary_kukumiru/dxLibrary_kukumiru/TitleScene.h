#pragma once
#include "SceneBase.h"

namespace Scene {
	class TitleScene :public SceneBase
	{
	public:
		TitleScene();
		~TitleScene();

		//SceneBase‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½B
		virtual void Calculation() override;
		virtual void TwoDimesionsDraw() override;
		virtual void ThreeDimesionsDraw() override;
	};
}