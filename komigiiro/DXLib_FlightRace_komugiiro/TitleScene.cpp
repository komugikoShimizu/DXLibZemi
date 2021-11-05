#include "TitleScene.h"
#include "DxLib.h"
 
namespace Scene
{
	void TitleScene::Calculation()
	{
		// printfDx("TitleScene::Calculation\n");
	}

	void TitleScene::TwoDimentionsDraw()
	{
		// printfDx("TitleScene::TwoDimentionsDraw\n");
	}

	void TitleScene::ThreeDimensionsDraw()
	{
		// printfDx("TitleScene::ThreeDimensionsDraw");
	}

	TransitionType TitleScene::GetNextScene()
	{
		if (CheckHitKey(KEY_INPUT_RETURN)) return TransitionType::NEXT;
		return TransitionType::STAY;
	}
}