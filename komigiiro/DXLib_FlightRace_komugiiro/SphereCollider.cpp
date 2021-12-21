#include "SphereCollider.h"

using namespace std;

namespace Collider
{

	SphereCollider::SphereCollider(float newRadius) // コライダークラスコンストラクタ
	{
		pivot = VGet(100, 100, 100);
		radius = newRadius;
	}

	SphereCollider::~SphereCollider() // コライダークラスデストラクタ
	{

	}
	void SphereCollider::Draw() // 描画クラス(デバッグ用)
	{
		DrawCircle(pivot.x, pivot.y, radius, GetColor(255, 255, 255), false);
	}

	VECTOR SphereCollider::RadiusAddVcetor() // 半径を加味したVECTOR型を返します
	{
		VECTOR vec = pivot;
		vec.x += radius;
		return vec;
	}

	float SphereCollider::Distance(VECTOR vec1, VECTOR vec2) // 2点間の距離を返します
	{
		float distance
			= (vec1.x - vec2.x) * (vec1.x - vec2.x)
			+ (vec1.y - vec2.y) * (vec1.y - vec2.y)
			+ (vec1.z - vec2.z) * (vec1.z - vec2.z);

		distance = std::sqrt(distance);

		return distance;
	}

	bool SphereCollider::HitCollider(SphereCollider * target, SphereCollider * comparison) // 円と円の当たり判定を値を返します
	{
		float targetDistance = SphereCollider::Distance(target->pivot, target->RadiusAddVcetor()); // 当たっているかを調べる側の原点から半径を加味した長さ
		float comparisonDistance = SphereCollider::Distance(comparison->pivot, comparison->RadiusAddVcetor()); // 比較対象の原点から半径を加味した長さ

		string str = "target distance = ";
		str += to_string(targetDistance);
		str += "\ncomparison distance = ";
		str += to_string(comparisonDistance);
		DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));

		bool hit = false;

		// 自身の原点と対象の原点までの距離を求める
		// その求めた値が双方の距離の論理和よりも大きいのであれば、当たっているためtrueに返却値を変更する
		// 2点間の原点 < 調査対象の大きさ + 比較対象の大きさ (distance(target <-> comparision) < targetDistance + comparisionDistance)
		if (SphereCollider::Distance(target->pivot, comparison->pivot) < targetDistance + comparisonDistance) hit = true;
		return hit;
	}
}