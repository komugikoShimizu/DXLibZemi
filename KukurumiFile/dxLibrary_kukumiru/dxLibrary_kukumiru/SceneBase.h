#pragma once

namespace Scene {
	class  SceneBase
	{
	public:
		virtual void Calculation();
		virtual void TwoDimesionsDraw();
		virtual void ThreeDimesionsDraw();
	};
}