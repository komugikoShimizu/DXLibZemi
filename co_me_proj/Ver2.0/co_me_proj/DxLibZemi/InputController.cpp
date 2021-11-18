#include "InputController.hpp"

namespace Input
{
	float InputController::GetYAxis()
	{
		if (Input::GetKey(KEY_INPUT_W))
		{
			return 1.0f;
		}
		if (Input::GetKey(KEY_INPUT_S))
		{
			return -1.0f;
		}
		return 0.0f;
	}

	float InputController::GetXAxis()
	{
		if (Input::GetKey(KEY_INPUT_D))
		{
			return 1.0f;
		}
		if (Input::GetKey(KEY_INPUT_A))
		{
			return -1.0f;
		}
		return 0.0f;
	}

	float InputController::GetZAxis()
	{
		if (Input::GetKey(KEY_INPUT_RIGHT))
		{
			return 1.0f;
		}
		if (Input::GetKey(KEY_INPUT_LEFT))
		{
			return -1.0f;
		}
		return 0.0f;
	}

	float InputController::GetCrrentMoveAxis()
	{
		if (Input::GetKey(KEY_INPUT_UP))
		{
			return 1.0f;
		}
		if (Input::GetKey(KEY_INPUT_DOWN))
		{
			return -1.0f;
		}
		return 0.0f;
	}

	bool InputController::GetIsFinishKey()
	{
		return Input::GetKey(KEY_INPUT_ESCAPE);
	}

	
}
