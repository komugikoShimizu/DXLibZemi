#pragma once
#include "KeyInput.hpp"
#include <DxLib.h>

namespace Input
{

	class InputController
	{
	public:
		inline InputController();
		inline ~InputController();
		float GetXAxis();
		float GetYAxis();
		float GetZAxis();
		float GetCrrentMoveAxis();
		bool GetIsFinishKey();
	};

	InputController::InputController()
	{
	}

	InputController::~InputController()
	{
	}
}