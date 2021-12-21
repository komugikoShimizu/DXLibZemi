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
		SphereCollider(float newRadius); // �R���X�g���N�^
		~SphereCollider(); // �f�X�g���N�^
		void Draw(); // �`��N���X
		VECTOR pivot = VECTOR(); // �R���C�_�[�̒��S�_
		float radius; // ���a

		VECTOR RadiusAddVcetor(); // ���a�������������W��Ԃ��N���X

		static float Distance(VECTOR vec1, VECTOR vec2); // 2�_�Ԃ̋�����Ԃ��ÓI�֐�
		static bool HitCollider(SphereCollider* target, SphereCollider* comparison); // �~�Ɖ~�̓����蔻����s���ÓI�֐�
	private:

	};

	SphereCollider::SphereCollider() {};
}