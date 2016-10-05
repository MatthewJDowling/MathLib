#include "Transform.h"
#include "sfwdraw.h"



Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;
	facing = 0;
}

vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}

void Transform::debugUpdate()
{
	if (position.x < 0)
	{
		position.x = 800; 
	}
	else if (position.x > 800)
	{
		position.x = 0;
	}

	if (position.y < 0)
	{
		position.y = 800;
	}
	else if (position.y > 800)
	{
		position.y = 0;
	}
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 12,12, WHITE);

	vec2 dirEnd = position + getDirection() * scale.x * 60;
	vec2 upEnd = position + perp(getDirection()) *scale.y * 45;


	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, BLUE);
	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, BLACK);
	
	
	
		
	
}

