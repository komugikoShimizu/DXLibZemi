#include "Surface.h"

using namespace std;

namespace Collider
{
	// 受け取った左下頂点と右上頂点をベースとした四角形平面を生成します
	Surface::Surface(VECTOR lowerLeftVertex, VECTOR upperRightVertex)
	{
		// 各長さ変数を左下頂点情報と右下頂点情報の差分に設定
		int width = upperRightVertex.x - lowerLeftVertex.x;
		int height = upperRightVertex.y - lowerLeftVertex.y;
		int depth = upperRightVertex.z - lowerLeftVertex.z;

		// 軸になっている点を除いた面の原点を生成、また軸情報を設定する
		if (width == 0)
		{
			shaft = 0;
			pivot = VGet(lowerLeftVertex.x, lowerLeftVertex.y + (height / 2), lowerLeftVertex.z + (depth / 2));
		}
		else if (height == 0)
		{
			shaft = 1;
			pivot = VGet(lowerLeftVertex.x + (width / 2), lowerLeftVertex.y, lowerLeftVertex.z + (depth / 2));
		}
		else if (depth == 0)
		{
			shaft = 2;
			pivot = VGet(lowerLeftVertex.x + (width / 2), lowerLeftVertex.y + (height / 2), lowerLeftVertex.z);
		}

		// 左下頂点と右上頂点を受け取った情報に設定 
		vertexs[0].position = VGet(lowerLeftVertex.x, lowerLeftVertex.y, lowerLeftVertex.z);
		vertexs[2].position = VGet(upperRightVertex.x, upperRightVertex.y, upperRightVertex.z);

		// 軸情報に合わせて残りの頂点情報を補間
		switch (shaft)
		{
		case 0:
			vertexs[1].position = VGet(lowerLeftVertex.x, lowerLeftVertex.y, upperRightVertex.z);
			vertexs[3].position = VGet(lowerLeftVertex.x, upperRightVertex.y, lowerLeftVertex.z);
			break;
		case 1:
			vertexs[1].position = VGet(upperRightVertex.x, lowerLeftVertex.y, lowerLeftVertex.z);
			vertexs[3].position = VGet(lowerLeftVertex.x, lowerLeftVertex.y, upperRightVertex.z);
			break;
		case 2:
			vertexs[1].position = VGet(upperRightVertex.x, lowerLeftVertex.y, lowerLeftVertex.z);
			vertexs[3].position = VGet(lowerLeftVertex.x, upperRightVertex.y, lowerLeftVertex.z);
			break;
		default:
			//delete this;
			break;
		}
	}

	void Surface::PivotSet(VECTOR newPibot)
	{
		VECTOR difference = VGet(newPibot.x - pivot.x, newPibot.y - pivot.y, newPibot.z - pivot.z); // 新しい原点と旧原点の差分を求める

		pivot = newPibot; // 新しい原点に更新

		for (int i = 0; i < 4; i++)
		{
			// 各頂点に対し、新しい原点に合わせた座標に移動を行う
			vertexs[i].position =
				VGet(vertexs[i].position.x + difference.x, vertexs[i].position.y + difference.y, vertexs[i].position.z + difference.z);
		}

		for (int i = 0; i < 4; i++)
		{
			int index = i != 3 ? i + 1 : 0;
			DrawLine3D(vertexs[i].position, vertexs[index].position, GetColor(255, 255, 255));
		}
	}

	Surface::~Surface()
	{

	}

	bool Surface::Detection(VECTOR vertexPosition)
	{
		// 軸に合わせた関数を実行
		// 始点と終点と対象の頂点の軸以外の座標情報を平面に置きかえ、外積の計算をする
		// 常に結果が-となった場合、この面に対し触れているため、trueを返す
		// 各軸で処理が異なるため、関数を分けてある
		switch (shaft)
		{
		case 0:
			return xBaseDetection(vertexPosition);
			break;
		case 1:
			return yBaseDetection(vertexPosition);
			break;
		case 2:
			return zBaseDetection(vertexPosition);
			break;
		default:
			return false;
			break;
		}
	}

	bool Surface::xBaseDetection(VECTOR vertexPosition)
	{
		float vectorLength = 0;
		for (int i = 0; i < 4; i++)
		{
			int index = i != 3 ? i + 1 : 0;

			vectorLength
				= (vertexs[index].position.y - vertexs[i].position.y) * (vertexPosition.z - vertexs[i].position.z)
				- (vertexPosition.y - vertexs[i].position.y) * (vertexs[index].position.z - vertexs[i].position.z);

			if (vectorLength > 0.0f) return false;
		}

		return true;
	}

	bool Surface::yBaseDetection(VECTOR vertexPosition)
	{
		float vectorLength = 0;
		for (int i = 0; i < 4; i++)
		{
			int index = i != 3 ? i + 1 : 0;

			vectorLength
				= (vertexs[index].position.z - vertexs[i].position.z) * (vertexPosition.x - vertexs[i].position.x)
				- (vertexPosition.z - vertexs[i].position.z) * (vertexs[index].position.x - vertexs[i].position.x);

			if (vectorLength > 0.0f) return false;
		}

		return true;
	}

	bool Surface::zBaseDetection(VECTOR vertexPosition)
	{
		float vectorLength = 0;
		for (int i = 0; i < 4; i++)
		{
			int index = i != 3 ? i + 1 : 0;

			vectorLength
				= (vertexs[index].position.y - vertexs[i].position.y) * (vertexPosition.x - vertexs[i].position.x)
				- (vertexPosition.y - vertexs[i].position.y) * (vertexs[index].position.x - vertexs[i].position.x);

			if (vectorLength > 0.0f) return false;
		}

		return true;
	}
}