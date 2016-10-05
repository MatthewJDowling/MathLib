#pragma once
#include "vec2.h"
#include "sfwdraw.h"
class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0, float w = 1, float h = 1, float a = 0);
	vec2 position; 
	vec2 scale;
	float facing; 
	
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	void debugUpdate();
	void debugDraw();
};