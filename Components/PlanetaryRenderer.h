#pragma once

#include "Transform.h"


class PlanetaryRenderer
{
public:
	PlanetaryRenderer(unsigned a_color, float a_size);

	

	unsigned int color;
		float size;

		void draw(Transform &planetTrans);
};