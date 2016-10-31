#include "SpaceShipRenderer.h"
#include "sfwdraw.h"
#include "shapeDraw.h"
SpaceshipRenderer::SpaceshipRenderer()
{
	color = MAGENTA;
}

void SpaceshipRenderer::draw(const mat3 & Camera,const Transform & ship)
{
	mat3 glob = ship.getGlobalTransform();

	vec3 F = Camera *glob *vec3{   5, 0, 1};
	vec3 L = Camera *glob *vec3{  -1,2, 1};
	vec3 R = Camera *glob *vec3{   -1,-2, 1};

	sfw::drawLine(L.x, L.y, F.x, F.y, color);
	sfw::drawLine(F.x, F.y, R.x, R.y, color);
	sfw::drawLine(R.x, R.y, L.x, L.y, color);
	
	

}