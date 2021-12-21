#include "SphereCollider.h"

using namespace std;

namespace Collider
{

	SphereCollider::SphereCollider(float newRadius) // �R���C�_�[�N���X�R���X�g���N�^
	{
		pivot = VGet(100, 100, 100);
		radius = newRadius;
	}

	SphereCollider::~SphereCollider() // �R���C�_�[�N���X�f�X�g���N�^
	{

	}
	void SphereCollider::Draw() // �`��N���X(�f�o�b�O�p)
	{
		DrawCircle(pivot.x, pivot.y, radius, GetColor(255, 255, 255), false);
	}

	VECTOR SphereCollider::RadiusAddVcetor() // ���a����������VECTOR�^��Ԃ��܂�
	{
		VECTOR vec = pivot;
		vec.x += radius;
		return vec;
	}

	float SphereCollider::Distance(VECTOR vec1, VECTOR vec2) // 2�_�Ԃ̋�����Ԃ��܂�
	{
		float distance
			= (vec1.x - vec2.x) * (vec1.x - vec2.x)
			+ (vec1.y - vec2.y) * (vec1.y - vec2.y)
			+ (vec1.z - vec2.z) * (vec1.z - vec2.z);

		distance = std::sqrt(distance);

		return distance;
	}

	bool SphereCollider::HitCollider(SphereCollider * target, SphereCollider * comparison) // �~�Ɖ~�̓����蔻���l��Ԃ��܂�
	{
		float targetDistance = SphereCollider::Distance(target->pivot, target->RadiusAddVcetor()); // �������Ă��邩�𒲂ׂ鑤�̌��_���甼�a��������������
		float comparisonDistance = SphereCollider::Distance(comparison->pivot, comparison->RadiusAddVcetor()); // ��r�Ώۂ̌��_���甼�a��������������

		string str = "target distance = ";
		str += to_string(targetDistance);
		str += "\ncomparison distance = ";
		str += to_string(comparisonDistance);
		DrawString(0, 0, str.c_str(), GetColor(255, 255, 255));

		bool hit = false;

		// ���g�̌��_�ƑΏۂ̌��_�܂ł̋��������߂�
		// ���̋��߂��l���o���̋����̘_���a�����傫���̂ł���΁A�������Ă��邽��true�ɕԋp�l��ύX����
		// 2�_�Ԃ̌��_ < �����Ώۂ̑傫�� + ��r�Ώۂ̑傫�� (distance(target <-> comparision) < targetDistance + comparisionDistance)
		if (SphereCollider::Distance(target->pivot, comparison->pivot) < targetDistance + comparisonDistance) hit = true;
		return hit;
	}
}