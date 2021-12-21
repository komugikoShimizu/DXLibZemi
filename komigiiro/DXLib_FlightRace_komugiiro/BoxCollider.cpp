#include "BoxCollider.h"

using namespace std;

namespace Collider
{
	BoxCollider::BoxCollider(float newWidth, float newHeight, float newDepth, VECTOR& newPibot)
	{
		pivot = &newPibot; // ���_�ݒ�

		// �e�����ݒ�
		width = newWidth;
		height = newHeight;
		depth = newDepth;

		// �e���_���\��
		VECTOR vertex0 = VGet(pivot->x - (width / 2), pivot->y - (height / 2), pivot->z - (depth / 2)); // ������O
		VECTOR vertex1 = VGet(pivot->x + (width / 2), pivot->y - (height / 2), pivot->z - (depth / 2)); // �E����O
		VECTOR vertex2 = VGet(pivot->x - (width / 2), pivot->y - (height / 2), pivot->z + (depth / 2)); // ������
		VECTOR vertex3 = VGet(pivot->x + (width / 2), pivot->y - (height / 2), pivot->z + (depth / 2)); // �E����
		VECTOR vertex4 = VGet(pivot->x - (width / 2), pivot->y + (height / 2), pivot->z - (depth / 2)); // �����O
		VECTOR vertex5 = VGet(pivot->x + (width / 2), pivot->y + (height / 2), pivot->z - (depth / 2)); // �E���O
		VECTOR vertex6 = VGet(pivot->x - (width / 2), pivot->y + (height / 2), pivot->z + (depth / 2)); // ���㉜
		VECTOR vertex7 = VGet(pivot->x + (width / 2), pivot->y + (height / 2), pivot->z + (depth / 2)); // �E�㉜

		surfaces[0] = Surface(vertex0, vertex6); // �����ʂ��\��
		surfaces[1] = Surface(vertex0, vertex3); // ���̖ʂ��\��
		surfaces[2] = Surface(vertex0, vertex5); // ��O�̖ʂ��\��
		surfaces[3] = Surface(vertex1, vertex7); // �E���ʂ��\��
		surfaces[4] = Surface(vertex4, vertex7); // ��̖ʂ��\��
		surfaces[5] = Surface(vertex2, vertex7); // ���̖ʂ��\��
	}

	BoxCollider::~BoxCollider()
	{

	}

	void BoxCollider::posSet()
	{
		// �ړ��p�֐�
		if (CheckHitKey(KEY_INPUT_A)) pivot->x -= 1;
		if (CheckHitKey(KEY_INPUT_D)) pivot->x += 1;
		if (CheckHitKey(KEY_INPUT_W)) pivot->y -= 1;
		if (CheckHitKey(KEY_INPUT_S)) pivot->y += 1;
		if (CheckHitKey(KEY_INPUT_Z)) pivot->z -= 1;
		if (CheckHitKey(KEY_INPUT_X)) pivot->z += 1;
	}

	void BoxCollider::Draw()
	{
		// �e�ʂɑ΂����_�̈ړ����w��
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
				// �e�ʂɑ΂������蔻����s���A�S�Ă���true���ԋp����Ă���Ȃ�true��Ԃ�
				if (target->surfaces[0].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[1].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[2].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[3].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[4].Detection(comparison->surfaces[index].vertexs[j].position)
					&& target->surfaces[5].Detection(comparison->surfaces[index].vertexs[j].position))
				{
					string str = "�Փ˂������_���W: x.";
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