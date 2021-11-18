#include"ResultScene.hpp"


namespace Scene
{
	void ResultScene::Calculation(SetDrawCameraInfo& info)
	{
		printfDx("ResultScene::Calculation\n");
	}

	void ResultScene::TwoDimensionsDraw()
	{
		printfDx("ResultScene::TwoDimensionsDraw\n");
	}

	void ResultScene::ThreeDimensionsDraw()
	{
		printfDx("ResultScene::ThreeDimensionsDraw\n");
	}

	TransitionType ResultScene::GetNextState()
	{
		static bool isHitKeyRetrun;
		bool beforeIsHitKeyRetrun = isHitKeyRetrun;
		isHitKeyRetrun = CheckHitKey(KEY_INPUT_RETURN) == 1;
		if (!isHitKeyRetrun) return TransitionType::STAY;
		if (beforeIsHitKeyRetrun) return TransitionType::STAY;
		return TransitionType::NEXT;
	}
}
