#pragma once
#include "SceneBase.h"

namespace Scene
{
	class ResultScene : public SceneBase
	{
	public:
		inline ResultScene();
		inline ~ResultScene();

		// SceneBase ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
		virtual void Calculation() override;
		virtual void TwoDimensionsDraw() override;
		virtual void ThreeDimensionsDraw() override;

	};

	ResultScene::ResultScene()
	{
	}

	ResultScene::~ResultScene()
	{
	}
}