#include "BoxCollider.h"

using namespace std;

namespace Collider
{
	BoxCollider::BoxCollider(float newWidth, float newHeight, float newDepth, VECTOR& newPibot)
	{
		pivot = &newPibot; // 原点設定

		// 各長さ設定
		width = newWidth;
		height = newHeight;
		depth = newDepth;

		// 各頂点を構成
		VECTOR vertex0 = VGet(pivot->x - (width / 2), pivot->y - (height / 2), pivot->z - (depth / 2)); // 左下手前
		VECTOR vertex1 = VGet(pivot->x + (width / 2), pivot->y - (height / 2), pivot->z - (depth / 2)); // 右下手前
		VECTOR vertex2 = VGet(pivot->x - (width / 2), pivot->y - (height / 2), pivot->z + (depth / 2)); // 左下奥
		VECTOR vertex3 = VGet(pivot->x + (width / 2), pivot->y - (height / 2), pivot->z + (depth / 2)); // 右下奥
		VECTOR vertex4 = VGet(pivot->x - (width / 2), pivot->y + (height / 2), pivot->z - (depth / 2)); // 左上手前
		VECTOR vertex5 = VGet(pivot->x + (width / 2), pivot->y + (height / 2), pivot->z - (depth / 2)); // 右上手前
		VECTOR vertex6 = VGet(pivot->x - (width / 2), pivot->y + (height / 2), pivot->z + (depth / 2)); // 左上奥
		VECTOR vertex7 = VGet(pivot->x + (width / 2), pivot->y + (height / 2), pivot->z + (depth / 2)); // 右上奥

		surfaces[0] = Surface(vertex0, vertex6); // 左側面を構成
		surfaces[1] = Surface(vertex0, vertex3); // 下の面を構成
		surfaces[2] = Surface(vertex0, vertex5); // 手前の面を構成
		surfaces[3] = Surface(vertex1, vertex7); // 右側面を構成
		surfaces[4] = Surface(vertex4, vertex7); // 上の面を構成
		surfaces[5] = Surface(vertex2, vertex7); // 奥の面を構成
	}

	BoxCollider::~BoxCollider()
	{

	}

	void BoxCollider::posSet()
	{
		// 移動用関数
		if (CheckHitKey(KEY_INPUT_A)) pivot->x -= 1;
		if (CheckHitKey(KEY_INPUT_D)) pivot->x += 1;
		if (CheckHitKey(KEY_INPUT_W)) pivot->y -= 1;
		if (CheckHitKey(KEY_INPUT_S)) pivot->y += 1;
		if (CheckHitKey(KEY_INPUT_Z)) pivot->z -= 1;
		if (CheckHitKey(KEY_INPUT_X)) pivot->z += 1;
	}

	void BoxCollider::Draw()
	{
		// 各面に対し原点の移動を指令
		surfaces[0].PivotSet(VGet(pivot->x - (width / 2), pivot->y, pivot->z));
		surfaces[1].PivotSet(VGet(pivot->x, pivot->y - (height / 2), pivot->z));
		surfaces[2].PivotSet(VGet(pivot->x, pivot->y, pivot->z - (depth / 2)));
		surfaces[3].PivotSet(VGet(pivot->x + (width / 2), pivot->y, pivot->z));
		surfaces[4].PivotSet(VGet(pivot->x, pivot->y + (height / 2), pivot->z));
		surfaces[5].PivotSet(VGet(pivot->x, pivot->y, pivot->z + (depth / 2)));
	}

	bool BoxCollider::HitCollider(BoxCollider * target, BoxCollider * comparison)
	{
		for (int i = 0; i < 2; i++)
		{
			int index = i > 0 ? 4 : 1;

			for (int j = 0; j < 4; j++)
			{
				// 各面に対し当たり判定を行い、全てからtrueが返却されているならtrueを返す
				if (target->surfaces[0].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[1].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[2].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[3].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[4].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[5].Detection(comparison->surfaces[index].vertexs[j].position))
				{
					string str = "衝突した頂点座標: x.";
					str += to_string(comparison->surfaces[index].vertexs[j].position.x);
					str += ": y.";
					str += to_string(comparison->surfaces[index].vertexs[j].position.y);
					str += ": z.";
					str += to_string(comparison->surfaces[index].vertexs[j].position.z);
					DrawString(100, 0, str.c_str(), GetColor(255, 255, 255));
					return true;
				}
			}
		}

		return false;
	}
}