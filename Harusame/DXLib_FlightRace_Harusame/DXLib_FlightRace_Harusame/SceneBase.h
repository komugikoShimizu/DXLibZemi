#pragma once
namespace Scene
{
	// �C���^�[�t�F�[�X
	class SceneBase
	{
	public:
		virtual void Calculation() = 0;
		virtual void TwoDimensionsDraw() = 0;
		virtual void ThreeDimensionsDraw() = 0;
	};
}