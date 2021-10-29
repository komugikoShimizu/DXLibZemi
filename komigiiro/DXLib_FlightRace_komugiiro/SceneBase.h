#pragma once

namespace Scene
{
	enum class TransitionType
	{
		STAY,
		NEXT,
		BACK,
	};

	// �C���^�[�t�F�C�X���쐬
	class SceneBase
	{
	public:
		virtual void Calculation() = 0;
		virtual void TwoDimentionsDraw() = 0;
		virtual void ThreeDimensionsDraw() = 0;
	};
}