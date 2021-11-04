#pragma once
#include <DxLib.h>

namespace Input
{
	enum class InputType
	{
		ADVANCE,	// 前進（左クリック）
		BACK,		// 後退（右クリック）
		ASCENT,		// 上昇（Ｗキー）
		DESCENT,	// 下降（Ｓキー）
		LEFT,		// 左移動（Ａキー）
		RIGHT,		// 右移動（Ｄキー）
		COUNT,		// 要素数
	};
/*
	class InputManager
	{
	public:
		inline InputManager();
		inline ~InputManager();
*/
		static bool isInputArray[(int)Input::InputType::COUNT];
		// 現在のフレームの入力を保存し、キーの入力情報を進める
		static void ProceedWithKeyState()
		{
			// 毎フレームキー入力を更新する処理
			isInputArray[(int)InputType::ADVANCE] = GetMouseInput() & MOUSE_INPUT_LEFT;
			isInputArray[(int)InputType::BACK] = GetMouseInput() & MOUSE_INPUT_RIGHT;
			isInputArray[(int)InputType::ASCENT] = CheckHitKey(KEY_INPUT_W);
			isInputArray[(int)InputType::DESCENT] = CheckHitKey(KEY_INPUT_S);
			isInputArray[(int)InputType::LEFT] = CheckHitKey(KEY_INPUT_A);
			isInputArray[(int)InputType::RIGHT] = CheckHitKey(KEY_INPUT_D);
		}

		// 前進入力があるか（押している間）
		static bool isAdvance() { return GetMouseInput()& MOUSE_INPUT_LEFT; }
		// 後退入力があるか（押している間）
		static bool isBack() { return GetMouseInput()& MOUSE_INPUT_RIGHT; }
		// 上昇入力があるか（押している間）
		static bool isAscent() { return CheckHitKey(KEY_INPUT_W); }
		// 下降入力があるか（押している間）
		static bool isDescent() { return CheckHitKey(KEY_INPUT_S); }
		// 左入力があるか（押している間）
		static bool isLeft() { return CheckHitKey(KEY_INPUT_A); }
		// 右入力があるか（押している間）
		static bool isRight() { return CheckHitKey(KEY_INPUT_D); }

		// 前進入力があるか（押したとき）
		static bool isAdvanceDown()
		{
			if (isInputArray[(int)InputType::ADVANCE]) return false;
			return GetMouseInput()& MOUSE_INPUT_LEFT;
		}
		// 後退入力があるか（押したとき）
		static bool isBackDown()
		{
			if (isInputArray[(int)InputType::BACK]) return false;
			return GetMouseInput()& MOUSE_INPUT_RIGHT;
		}
		// 上昇入力があるか（押したとき）
		static bool isAscentDown()
		{
			if (isInputArray[(int)InputType::ASCENT]) return false;
			return CheckHitKey(KEY_INPUT_W);
		}
		// 下降入力があるか（押したとき）
		static bool isDescentDown()
		{
			if (isInputArray[(int)InputType::DESCENT]) return false;
			return CheckHitKey(KEY_INPUT_S);
		}
		// 左入力があるか（押したとき）
		static bool isLeftDown()
		{
			if (isInputArray[(int)InputType::LEFT]) return false;
			return CheckHitKey(KEY_INPUT_A);
		}
		// 右入力があるか（押したとき）
		static bool isRightDown()
		{
			if (isInputArray[(int)InputType::RIGHT]) return false;
			return CheckHitKey(KEY_INPUT_D);
		}

		// 前進入力があるか（離したとき）
		static bool isAdvanceUp()
		{
			if (GetMouseInput() & MOUSE_INPUT_LEFT) return false;
			return isInputArray[(int)InputType::ADVANCE];
		}
		// 後退入力があるか（離したとき）
		static bool isBackUp()
		{
			if (GetMouseInput() & MOUSE_INPUT_RIGHT) return false;
			return isInputArray[(int)InputType::BACK];
		}
		// 上昇入力があるか（離したとき）
		static bool isAscentUp()
		{
			if (CheckHitKey(KEY_INPUT_W)) return false;
			return isInputArray[(int)InputType::ASCENT];
		}
		// 下降入力があるか（離したとき）
		static bool isDescentUp()
		{
			if (CheckHitKey(KEY_INPUT_S)) return false;
			return isInputArray[(int)InputType::DESCENT];
		}
		// 左入力があるか（離したとき）
		static bool isLeftUp()
		{
			if (CheckHitKey(KEY_INPUT_A)) return false;
			return isInputArray[(int)InputType::LEFT];
		}
		// 右入力があるか（離したとき）
		static bool isRightUp()
		{
			if (CheckHitKey(KEY_INPUT_D)) return false;
			return isInputArray[(int)InputType::RIGHT];
		}

		// 指定した入力があるか（押している間）
		static bool isInput(InputType type)
		{
			// 指定された入力に対応する処理を呼ぶ
			switch (type)
			{
			case Input::InputType::ADVANCE:
				return isAdvance();
			case Input::InputType::BACK:
				return isBack();
			case Input::InputType::ASCENT:
				return isAscent();
			case Input::InputType::DESCENT:
				return isDescent();
			case Input::InputType::LEFT:
				return isLeft();
			case Input::InputType::RIGHT:
				return isRight();
			default:
				return false;
			}
		}
		// 指定した入力があるか（押したとき）
		static bool isInputDown(InputType type)
		{
			// 指定された入力に対応する処理を呼ぶ
			switch (type)
			{
			case Input::InputType::ADVANCE:
				return isAdvanceDown();
			case Input::InputType::BACK:
				return isBackDown();
			case Input::InputType::ASCENT:
				return isAscentDown();
			case Input::InputType::DESCENT:
				return isDescentDown();
			case Input::InputType::LEFT:
				return isLeftDown();
			case Input::InputType::RIGHT:
				return isRightDown();
			default:
				return false;
			}
		}
		// 指定した入力があるか（話したとき）
		static bool isInputUp(InputType type)
		{
			// 指定された入力に対応する処理を呼ぶ
			switch (type)
			{
			case Input::InputType::ADVANCE:
				return isAdvanceUp();
			case Input::InputType::BACK:
				return isBackUp();
			case Input::InputType::ASCENT:
				return isAscentUp();
			case Input::InputType::DESCENT:
				return isDescentUp();
			case Input::InputType::LEFT:
				return isLeftUp();
			case Input::InputType::RIGHT:
				return isRightUp();
			default:
				return false;
			}
		}

	/*InputManager::InputManager()
	{
		for (int i = 0; i < (int)Input::InputType::COUNT; ++i)
		{
			isInputArray[i] = false;
		}
	}

	InputManager::~InputManager()
	{
	}*/
}