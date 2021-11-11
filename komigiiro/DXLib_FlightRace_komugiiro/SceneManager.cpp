#include "SceneManager.h"

namespace Scene
{
	bool SceneManager::SceneProcess()
	{
		clsDx();
		scenes[(int)state]->Calculation();
		scenes[(int)state]->TwoDimentionsDraw();
		scenes[(int)state]->ThreeDimensionsDraw();

		switch (scenes[(int)state]->GetNextScene())
		{
		case TransitionType::STAY:
			break;
		case TransitionType::NEXT:
			state = (StateType)(((int)state + 1) % (int)StateType::COUNT);
			break;
		case TransitionType::BACK:
			state = (StateType)(((int)state - 1) % (int)StateType::COUNT % (int)StateType::COUNT);
			break;
		default:
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) return true;
		return false;
	}
}