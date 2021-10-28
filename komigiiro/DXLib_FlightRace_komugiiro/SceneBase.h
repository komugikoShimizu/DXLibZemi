#pragma once

namespace Scene
{
	// インターフェイスを作成
	class SceneBase
	{
	public:
		virtual void Calculation() = 0;
		virtual void TwoDimentionsDraw() = 0;
		virtual void ThreeDimensionsDraw() = 0;
	};
}