#include "TitleScene.hpp"


namespace Scene
{
	void TitleScene::Calculation(SetDrawCameraInfo& info)
	{
		printfDx("TitleScene::Calculation\n");
	}

	void TitleScene::TwoDimensionsDraw()
	{
		printfDx("TitleScene::TwoDimensionsDraw\n");
	}

	void TitleScene::ThreeDimensionsDraw()
	{
		printfDx("TitleScene::ThreeDimensionsDraw\n");
	}

	TransitionType TitleScene::GetNextState()
	{
		static bool isHitKeyRetrun;
		bool beforeIsHitKeyRetrun = isHitKeyRetrun;
		isHitKeyRetrun = CheckHitKey(KEY_INPUT_RETURN) == 1;
		if (!isHitKeyRetrun) return TransitionType::STAY;
		if (beforeIsHitKeyRetrun) return TransitionType::STAY;
		return TransitionType::NEXT;
	}
}
