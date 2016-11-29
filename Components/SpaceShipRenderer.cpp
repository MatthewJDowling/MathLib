#include "SpaceShipRenderer.h"
#include "sfwdraw.h"
#include "shapeDraw.h"
SpaceshipRenderer::SpaceshipRenderer()
{
	color = RED;
}

void SpaceshipRenderer::draw(const mat3 & Camera,const Transform & ship)
{
	mat3 glob = ship.getGlobalTransform();

	vec3 tr = Camera *glob *vec3{  1, 1, 1};
	vec3 tl = Camera *glob *vec3{ -1, 1, 1};
	vec3 bl = Camera *glob *vec3{ -1,-1, 1};
	vec3 br= Camera *glob *vec3{  1,-1, 1};

	sfw::drawLine(tr.x, tr.y, tl.x, tl.y, color);
	sfw::drawLine(tl.x, tl.y, bl.x, bl.y, color);
	sfw::drawLine(bl.x, bl.y, br.x, br.y, color);
	sfw::drawLine(br.x, br.y, tr.x, tr.y, color);
	

}