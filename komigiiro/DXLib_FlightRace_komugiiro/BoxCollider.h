#pragma once
#include "DxLib.h"
#include "Surface.h"
#include <cmath>
#include <string>

namespace Collider
{
	class Surface;

	class BoxCollider
	{
	public:
		inline BoxCollider();
		BoxCollider(float width, float height, float depth, VECTOR& newPibot);
		~BoxCollider();

		VECTOR* pivot = nullptr;
		float width;
		float height;
		float depth;

		Surface surfaces[6];

		void Draw();
		void posSet();

		static bool HitCollider(BoxCollider* target, BoxCollider* comparison);
	private:

	};

	BoxCollider::BoxCollider() {};
}