#pragma once
#include "UIUtilty.h"

using namespace UI;

namespace Scene
{
	enum class TransitionType
	{
		STAY,
		NEXT,
		BACK,
	};

	// インターフェイスを作成
	class SceneBase
	{
	public:
		virtual void Calculation() = 0;
		virtual void TwoDimentionsDraw() = 0;
		virtual void ThreeDimensionsDraw() = 0;
		virtual TransitionType GetNextScene() = 0;
	};
}