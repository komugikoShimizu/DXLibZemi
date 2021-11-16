#pragma once
#include "SceneBase.h"

namespace Scene
{
	class TitleScene : public SceneBase
	{
	public:
		inline TitleScene();
		inline ~TitleScene();

		// SceneBase ‚ð‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
		virtual void Calculation() override;

		virtual void TwoDimentionsDraw() override;

		virtual void ThreeDimensionsDraw() override;

		virtual TransitionType GetNextScene() override;

	private:
	};

	TitleScene::TitleScene()
	{
		ui->CanvasSizeCreate(50);
		ui->FontSeter(50);
		ui->FontSeter(40);
		ui->FontSeter(30);
		ui->FontSeter(20);
		ui->FontSeter(10);
	}

	TitleScene::~TitleScene()
	{
	}
}