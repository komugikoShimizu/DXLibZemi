#pragma once
#include "DxLib.h"

namespace Collider
{
	struct vertex
	{
	public:
		VECTOR position = VGet(0, 0, 0);
	};

	class Surface
	{
	public:
		inline Surface();
		Surface(VECTOR lowerLeftVertex, VECTOR upperRightVertex);
		~Surface();

		int shaft = -1;
		vertex vertexs[4];

		void PivotSet(VECTOR);
		bool Detection(VECTOR);
	private:
		bool xBaseDetection(VECTOR vertexPosition);
		bool yBaseDetection(VECTOR vertexPosition);
		bool zBaseDetection(VECTOR vertexPosition);
		VECTOR pivot;
	};

	Surface::Surface()
	{
		vertexs[0] = vertex();
		vertexs[1] = vertex();
		vertexs[2] = vertex();
		vertexs[3] = vertex();
	}
}