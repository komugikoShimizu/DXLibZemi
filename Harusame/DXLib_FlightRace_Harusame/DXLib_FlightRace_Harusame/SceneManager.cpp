#include "SceneManager.h"

namespace Scene
{
	bool SceneManager::SceneProcess()
	{
		// Debug—p•`‰æ‚Ì‰Šú‰»
		clsDx();
		scenes[(int)state]->Calculation();
		scenes[(int)state]->ThreeDimensionsDraw();
		scenes[(int)state]->TwoDimensionsDraw();

		switch (scenes[(int)state]->GetNextState())
		{
		case TransitionType::STAY:
			break;
		case TransitionType::NEXT:
			state = (StateType)(((int)state + 1) % (int)StateType::COUNT);
			break;
		case TransitionType::BACK:
			state = (StateType)(((int)state - 1 + (int)StateType::COUNT) % (int)StateType::COUNT);
			break;
		default:
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) return true;
		return false;
	}
}