#include "SceneManager.hpp"


namespace Scene
{
	/// <summary>
	/// Scene�Ǘ��֐�
	/// </summary>
	/// <returns>isFinish</returns>
	bool SceneManager::SceneProcess()
	{
		ClearDrawScreen();
		// Debug�p�`��̏�����
		clsDx();
		// �Ή����Ă�V�[���̉��Z�֐����R�[��
		scenes[(int)state]->Calculation(info);
		// �J������ݒ肷�邽�߂̏��t��SetDrawScreen�֐�
		SetDraw_Screen(info);
		// �m�[�}����SetDrawScreen�֐�
		// SetDraw_Screen(true);
		// �Ή����Ă�V�[����3D�`��֐����R�[��
		scenes[(int)state]->ThreeDimensionsDraw();
		// �Ή����Ă�V�[����2D�`��֐����R�[��
		scenes[(int)state]->TwoDimensionsDraw();
		// ��ʂ�\������
		ScreenFlip();

		// ���̃V�[���ւ̑J�ڏ��̎擾
		switch (scenes[(int)state]->GetNextState())
		{
		case TransitionType::STAY:
			// �������Ȃ�
			break;
		case TransitionType::NEXT:
			// state��1�i�߂� Count�ȏ�͌J��Ԃ�
			state = (StateType)(((int)state + 1) % (int)StateType::COUNT);
			break;
		case TransitionType::BACK:
			// state��1�߂� 0�ȉ��͌J��Ԃ�
			state = (StateType)(((int)state - 1 + (int)StateType::COUNT) % (int)StateType::COUNT);
			break;
		default:
			break;
		}
		bool isHitKeyEscape = false;
		static bool beforeIsHitKeyEscape = isHitKeyEscape;
		isHitKeyEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 1;
		if (isHitKeyEscape && beforeIsHitKeyEscape) return true;
		return false;
	}

	// �ʏ��SetDrawScreen�֐�
	void SceneManager::SetDraw_Screen(const bool& clear = true)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		if (clear)
		{
			ClearDrawScreen();
		}
	}

	// �J�����ݒ�t����SetDrawScreen�֐�(��̂��܂��Ȃ�)
	void SceneManager::SetDraw_Screen(const SetDrawCameraInfo& info)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		SetCameraNearFar(info.near_, info.far_);
		SetupCamera_Perspective(info.fov);
		SetCameraPositionAndTargetAndUpVec(info.campos.get(), info.camvec.get(), info.camup.get());
	}
}
