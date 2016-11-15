#include "shapeDraw.h"
#include "sfwdraw.h"
#include "shapes.h"

void drawCircle(const Circle & C, unsigned color)
{
	sfw::drawCircle(C.pos.x, C.pos.y, C.rad, 12U, color);
}

void drawAABB(const AABB &box, unsigned color)
{
	vec2 A = vec2{ box.min().x, box.max().y };
	vec2 B = vec2{ box.max().x, box.max().y };
	vec2 C = vec2{ box.max().x, box.min().y };
	vec2 D = vec2{ box.min().x, box.min().y };

	sfw::drawLine(A.x, A.y,	B.x, B.y, color);
	sfw::drawLine(B.x, B.y, C.x, C.y, color);
	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	sfw::drawLine(D.x, D.y, A.x, A.y, color);

	
}

void drawPlane(const Plane &L, unsigned color)
{
	sfw::drawCircle(L.pos.x, L.pos.y, 12, 12, color);

	sfw::drawLine(L.pos.x, L.pos.y, L.pos.x + L.dir.x, L.pos.x + L.dir.y,color);
	
	vec2 left = -perp(normal(L.dir)); 
	vec2 right = perp(normal(L.dir));

	sfw::drawLine(L.pos.x, L.pos.y,
				  L.pos.x + left.x * 20, L.pos.y + left.y * 20, color);

	sfw::drawLine(L.pos.x, L.pos.y,
				  L.pos.x + right.x * 20, L.pos.y + right.y * 20, color);
}

void drawHull(const Hull & B, unsigned color)
{
	for (int i = 0; i < B.size && i < 16; ++i)
	{
		sfw::drawLine(B.vertices[i].x, B.vertices[i].y,
			B.vertices[(i + 1) % B.size].x,
			B.vertices[(i + 1) % B.size].y, RED);
						
	}
}
