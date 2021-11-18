#pragma once
#include "DXLib_vec.hpp"

namespace Scene
{
	// ���̃X�e�[�g�̃^�C�v
	enum class TransitionType
	{
		STAY,
		NEXT,
		BACK,
	};

	// �J�����̏��
	typedef struct
	{
	public:
		VECTOR_ref campos;
		VECTOR_ref camvec;
		VECTOR_ref camup;
		float fov;
		float near_;
		float far_;
	}SetDrawCameraInfo;

	// �V�[���̃C���^�[�t�F�C�X
	class SceneBase
	{
	public:
		// ���Z�֐�
		virtual void Calculation(SetDrawCameraInfo&) = 0;
		// �񎟌��`��֐�
		virtual void TwoDimensionsDraw() = 0;
		// �O�����`��֐�
		virtual void ThreeDimensionsDraw() = 0;
		// ���̃X�e�[�g�o�͊֐�
		virtual TransitionType GetNextState() = 0;
	};
}
