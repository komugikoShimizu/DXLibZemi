#include "Surface.h"

using namespace std;

namespace Collider
{
	// �󂯎�����������_�ƉE�㒸�_���x�[�X�Ƃ����l�p�`���ʂ𐶐����܂�
	Surface::Surface(VECTOR lowerLeftVertex, VECTOR upperRightVertex)
	{
		// �e�����ϐ����������_���ƉE�����_���̍����ɐݒ�
		int width = upperRightVertex.x - lowerLeftVertex.x;
		int height = upperRightVertex.y - lowerLeftVertex.y;
		int depth = upperRightVertex.z - lowerLeftVertex.z;

		// ���ɂȂ��Ă���_���������ʂ̌��_�𐶐��A�܂�������ݒ肷��
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

		// �������_�ƉE�㒸�_���󂯎�������ɐݒ� 
		vertexs[0].position = VGet(lowerLeftVertex.x, lowerLeftVertex.y, lowerLeftVertex.z);
		vertexs[2].position = VGet(upperRightVertex.x, upperRightVertex.y, upperRightVertex.z);

		// �����ɍ��킹�Ďc��̒��_������
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
		VECTOR difference = VGet(newPibot.x - pivot.x, newPibot.y - pivot.y, newPibot.z - pivot.z); // �V�������_�Ƌ����_�̍��������߂�

		pivot = newPibot; // �V�������_�ɍX�V

		for (int i = 0; i < 4; i++)
		{
			// �e���_�ɑ΂��A�V�������_�ɍ��킹�����W�Ɉړ����s��
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
		// ���ɍ��킹���֐������s
		// �n�_�ƏI�_�ƑΏۂ̒��_�̎��ȊO�̍��W���𕽖ʂɒu�������A�O�ς̌v�Z������
		// ��Ɍ��ʂ�-�ƂȂ����ꍇ�A���̖ʂɑ΂��G��Ă��邽�߁Atrue��Ԃ�
		// �e���ŏ������قȂ邽�߁A�֐��𕪂��Ă���
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