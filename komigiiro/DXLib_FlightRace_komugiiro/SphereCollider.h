#pragma once
#include "DxLib.h"
#include <cmath>
#include <string>

namespace Collider
{
	class SphereCollider
	{
	public:
		inline SphereCollider();
		SphereCollider(float newRadius); // コンストラクタ
		~SphereCollider(); // デストラクタ
		void Draw(); // 描画クラス
		VECTOR pivot = VECTOR(); // コライダーの中心点
		float radius; // 半径

		VECTOR RadiusAddVcetor(); // 半径を加味した座標を返すクラス

		static float Distance(VECTOR vec1, VECTOR vec2); // 2点間の距離を返す静的関数
		static bool HitCollider(SphereCollider* target, SphereCollider* comparison); // 円と円の当たり判定を行う静的関数
	private:

	};

	SphereCollider::SphereCollider() {};
}