#include "shapeDraw.h"
#include "sfwdraw.h"
#include "shapes.h"

void drawCircle(const Circle & C, unsigned color)
{
	sfw::drawCircle(C.pos.x, C.pos.y, C.rad, 12U, color);
}

void drawAABB(const AABB &B, unsigned color)
{
	sfw::drawLine(B.min().x, B.pos.y,    B.max().x,   B.pos.y,   color);
	sfw::drawLine(B.min().x, B.pos.y,    B.pos.x,     B.max().y, color);
	sfw::drawLine(B.min().x, B.max().y,  B.max().x,   B.max().y, color);
	sfw::drawLine(B.max().x, B.min().y,  B.max().x,   B.max().y, color);
	
}