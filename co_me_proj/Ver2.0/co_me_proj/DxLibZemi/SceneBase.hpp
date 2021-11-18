#pragma once
#include "DXLib_vec.hpp"

namespace Scene
{
	// 次のステートのタイプ
	enum class TransitionType
	{
		STAY,
		NEXT,
		BACK,
	};

	// カメラの情報
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

	// シーンのインターフェイス
	class SceneBase
	{
	public:
		// 演算関数
		virtual void Calculation(SetDrawCameraInfo&) = 0;
		// 二次元描画関数
		virtual void TwoDimensionsDraw() = 0;
		// 三次元描画関数
		virtual void ThreeDimensionsDraw() = 0;
		// 次のステート出力関数
		virtual TransitionType GetNextState() = 0;
	};
}
