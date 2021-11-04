//#include "InputManager.h"
//
//namespace Input
//{
//	// キー入力の状態を正しくする
//	void /*InputManager::*/ProceedWithKeyState()
//	{
//		// 毎フレームキー入力を更新する処理
//		isInputArray[(int)InputType::ADVANCE] = GetMouseInput() & MOUSE_INPUT_LEFT;
//		isInputArray[(int)InputType::BACK] = GetMouseInput() & MOUSE_INPUT_RIGHT;
//		isInputArray[(int)InputType::ASCENT] = CheckHitKey(KEY_INPUT_W);
//		isInputArray[(int)InputType::DESCENT] = CheckHitKey(KEY_INPUT_S);
//		isInputArray[(int)InputType::LEFT] = CheckHitKey(KEY_INPUT_A);
//		isInputArray[(int)InputType::RIGHT] = CheckHitKey(KEY_INPUT_D);
//	}
//
//	bool /*InputManager::*/isInput(InputType type)
//	{
//		// 指定された入力に対応する処理を呼ぶ
//		switch (type)
//		{
//		case Input::InputType::ADVANCE:
//			return isAdvance();
//		case Input::InputType::BACK:
//			return isBack();
//		case Input::InputType::ASCENT:
//			return isAscent();
//		case Input::InputType::DESCENT:
//			return isDescent();
//		case Input::InputType::LEFT:
//			return isLeft();
//		case Input::InputType::RIGHT:
//			return isRight();
//		default:
//			return false;
//		}
//	}
//	bool /*InputManager::*/isInputDown(InputType type)
//	{
//		// 指定された入力に対応する処理を呼ぶ
//		switch (type)
//		{
//		case Input::InputType::ADVANCE:
//			return isAdvanceDown();
//		case Input::InputType::BACK:
//			return isBackDown();
//		case Input::InputType::ASCENT:
//			return isAscentDown();
//		case Input::InputType::DESCENT:
//			return isDescentDown();
//		case Input::InputType::LEFT:
//			return isLeftDown();
//		case Input::InputType::RIGHT:
//			return isRightDown();
//		default:
//			return false;
//		}
//	}
//	bool /*InputManager::*/isInputUp(InputType type)
//	{
//		// 指定された入力に対応する処理を呼ぶ
//		switch (type)
//		{
//		case Input::InputType::ADVANCE:
//			return isAdvanceUp();
//		case Input::InputType::BACK:
//			return isBackUp();
//		case Input::InputType::ASCENT:
//			return isAscentUp();
//		case Input::InputType::DESCENT:
//			return isDescentUp();
//		case Input::InputType::LEFT:
//			return isLeftUp();
//		case Input::InputType::RIGHT:
//			return isRightUp();
//		default:
//			return false;
//		}
//	}
//
//	bool /*InputManager::*/isAdvance() { return GetMouseInput() & MOUSE_INPUT_LEFT; }
//	bool /*InputManager::*/isBack() { return GetMouseInput() & MOUSE_INPUT_RIGHT; }
//	bool /*InputManager::*/isAscent() { return CheckHitKey(KEY_INPUT_W); }
//	bool /*InputManager::*/isDescent() { return CheckHitKey(KEY_INPUT_S); }
//	bool /*InputManager::*/isLeft() { return CheckHitKey(KEY_INPUT_A); }
//	bool /*InputManager::*/isRight() { return CheckHitKey(KEY_INPUT_D); }
//
//	bool /*InputManager::*/isAdvanceDown()
//	{
//		if (isInputArray[(int)InputType::ADVANCE]) return false;
//		return GetMouseInput() & MOUSE_INPUT_LEFT;
//	}
//	bool /*InputManager::*/isAscentDown()
//	{
//		if (isInputArray[(int)InputType::ASCENT]) return false;
//		return CheckHitKey(KEY_INPUT_W);
//	}
//	bool /*InputManager::*/isDescentDown()
//	{
//		if (isInputArray[(int)InputType::DESCENT]) return false;
//		return CheckHitKey(KEY_INPUT_S);
//	}
//	bool /*InputManager::*/isLeftDown()
//	{
//		if (isInputArray[(int)InputType::LEFT]) return false;
//		return CheckHitKey(KEY_INPUT_A);
//	}
//	bool /*InputManager::*/isRightDown()
//	{
//		if (isInputArray[(int)InputType::RIGHT]) return false;
//		return CheckHitKey(KEY_INPUT_D);
//	}
//
//	bool /*InputManager::*/isAdvanceUp()
//	{
//		if (GetMouseInput() & MOUSE_INPUT_LEFT) return false;
//		return isInputArray[(int)InputType::ADVANCE];
//	}
//	bool /*InputManager::*/isBackUp()
//	{
//		if (GetMouseInput() & MOUSE_INPUT_RIGHT) return false;
//		return isInputArray[(int)InputType::BACK];
//	}
//	bool /*InputManager::*/isAscentUp()
//	{
//		if (CheckHitKey(KEY_INPUT_W)) return false;
//		return isInputArray[(int)InputType::ASCENT];
//	}
//	bool /*InputManager::*/isDescentUp()
//	{
//		if (CheckHitKey(KEY_INPUT_S)) return false;
//		return isInputArray[(int)InputType::DESCENT];
//	}
//	bool /*InputManager::*/isLeftUp()
//	{
//		if (CheckHitKey(KEY_INPUT_A)) return false;
//		return isInputArray[(int)InputType::LEFT];
//	}
//	bool /*InputManager::*/isRightUp()
//	{
//		if (CheckHitKey(KEY_INPUT_D)) return false;
//		return isInputArray[(int)InputType::RIGHT];
//	}
//}