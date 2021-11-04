#pragma once
namespace Scene
{
	enum class TransitionType
	{
		STAY,
		NEXT,
		BACK,
	};

	// �C���^�[�t�F�[�X
	class SceneBase
	{
	public:
		virtual void Calculation() = 0;
		virtual void TwoDimensionsDraw() = 0;
		virtual void ThreeDimensionsDraw() = 0;
		virtual TransitionType GetNextState() = 0;
	};
}