#include "PlanetaryRenderer.h"

#include "sfwdraw.h"
PlanetaryRenderer::PlanetaryRenderer(unsigned a_color, float a_size)
{
	color = a_color;
	size = a_size; 


}

void PlanetaryRenderer::draw(Transform & planetTrans)
{
	mat3 glob = planetTrans.getGlobalTransform();

	float xRad = magnitude(glob * vec3{ size, 0, 0 });
	float yRad = magnitude(glob * vec3{ 0,  size,  0 });

	vec2 pos = glob[2].xy; 


	float rad = xRad > yRad ? xRad : yRad; 

	sfw::drawCircle(pos.x, pos.y, rad, 12U, color);
}
