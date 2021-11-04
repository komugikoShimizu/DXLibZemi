#pragma once
#include <DxLib.h>

namespace Input
{
	enum class InputType
	{
		ADVANCE,	// �O�i�i���N���b�N�j
		BACK,		// ��ށi�E�N���b�N�j
		ASCENT,		// �㏸�i�v�L�[�j
		DESCENT,	// ���~�i�r�L�[�j
		LEFT,		// ���ړ��i�`�L�[�j
		RIGHT,		// �E�ړ��i�c�L�[�j
		COUNT,		// �v�f��
	};
/*
	class InputManager
	{
	public:
		inline InputManager();
		inline ~InputManager();
*/
		static bool isInputArray[(int)Input::InputType::COUNT];
		// ���݂̃t���[���̓��͂�ۑ����A�L�[�̓��͏���i�߂�
		static void ProceedWithKeyState()
		{
			// ���t���[���L�[���͂��X�V���鏈��
			isInputArray[(int)InputType::ADVANCE] = GetMouseInput() & MOUSE_INPUT_LEFT;
			isInputArray[(int)InputType::BACK] = GetMouseInput() & MOUSE_INPUT_RIGHT;
			isInputArray[(int)InputType::ASCENT] = CheckHitKey(KEY_INPUT_W);
			isInputArray[(int)InputType::DESCENT] = CheckHitKey(KEY_INPUT_S);
			isInputArray[(int)InputType::LEFT] = CheckHitKey(KEY_INPUT_A);
			isInputArray[(int)InputType::RIGHT] = CheckHitKey(KEY_INPUT_D);
		}

		// �O�i���͂����邩�i�����Ă���ԁj
		static bool isAdvance() { return GetMouseInput()& MOUSE_INPUT_LEFT; }
		// ��ޓ��͂����邩�i�����Ă���ԁj
		static bool isBack() { return GetMouseInput()& MOUSE_INPUT_RIGHT; }
		// �㏸���͂����邩�i�����Ă���ԁj
		static bool isAscent() { return CheckHitKey(KEY_INPUT_W); }
		// ���~���͂����邩�i�����Ă���ԁj
		static bool isDescent() { return CheckHitKey(KEY_INPUT_S); }
		// �����͂����邩�i�����Ă���ԁj
		static bool isLeft() { return CheckHitKey(KEY_INPUT_A); }
		// �E���͂����邩�i�����Ă���ԁj
		static bool isRight() { return CheckHitKey(KEY_INPUT_D); }

		// �O�i���͂����邩�i�������Ƃ��j
		static bool isAdvanceDown()
		{
			if (isInputArray[(int)InputType::ADVANCE]) return false;
			return GetMouseInput()& MOUSE_INPUT_LEFT;
		}
		// ��ޓ��͂����邩�i�������Ƃ��j
		static bool isBackDown()
		{
			if (isInputArray[(int)InputType::BACK]) return false;
			return GetMouseInput()& MOUSE_INPUT_RIGHT;
		}
		// �㏸���͂����邩�i�������Ƃ��j
		static bool isAscentDown()
		{
			if (isInputArray[(int)InputType::ASCENT]) return false;
			return CheckHitKey(KEY_INPUT_W);
		}
		// ���~���͂����邩�i�������Ƃ��j
		static bool isDescentDown()
		{
			if (isInputArray[(int)InputType::DESCENT]) return false;
			return CheckHitKey(KEY_INPUT_S);
		}
		// �����͂����邩�i�������Ƃ��j
		static bool isLeftDown()
		{
			if (isInputArray[(int)InputType::LEFT]) return false;
			return CheckHitKey(KEY_INPUT_A);
		}
		// �E���͂����邩�i�������Ƃ��j
		static bool isRightDown()
		{
			if (isInputArray[(int)InputType::RIGHT]) return false;
			return CheckHitKey(KEY_INPUT_D);
		}

		// �O�i���͂����邩�i�������Ƃ��j
		static bool isAdvanceUp()
		{
			if (GetMouseInput() & MOUSE_INPUT_LEFT) return false;
			return isInputArray[(int)InputType::ADVANCE];
		}
		// ��ޓ��͂����邩�i�������Ƃ��j
		static bool isBackUp()
		{
			if (GetMouseInput() & MOUSE_INPUT_RIGHT) return false;
			return isInputArray[(int)InputType::BACK];
		}
		// �㏸���͂����邩�i�������Ƃ��j
		static bool isAscentUp()
		{
			if (CheckHitKey(KEY_INPUT_W)) return false;
			return isInputArray[(int)InputType::ASCENT];
		}
		// ���~���͂����邩�i�������Ƃ��j
		static bool isDescentUp()
		{
			if (CheckHitKey(KEY_INPUT_S)) return false;
			return isInputArray[(int)InputType::DESCENT];
		}
		// �����͂����邩�i�������Ƃ��j
		static bool isLeftUp()
		{
			if (CheckHitKey(KEY_INPUT_A)) return false;
			return isInputArray[(int)InputType::LEFT];
		}
		// �E���͂����邩�i�������Ƃ��j
		static bool isRightUp()
		{
			if (CheckHitKey(KEY_INPUT_D)) return false;
			return isInputArray[(int)InputType::RIGHT];
		}

		// �w�肵�����͂����邩�i�����Ă���ԁj
		static bool isInput(InputType type)
		{
			// �w�肳�ꂽ���͂ɑΉ����鏈�����Ă�
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
		// �w�肵�����͂����邩�i�������Ƃ��j
		static bool isInputDown(InputType type)
		{
			// �w�肳�ꂽ���͂ɑΉ����鏈�����Ă�
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
		// �w�肵�����͂����邩�i�b�����Ƃ��j
		static bool isInputUp(InputType type)
		{
			// �w�肳�ꂽ���͂ɑΉ����鏈�����Ă�
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