#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "mat3.h"
#include "cmath"
class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0);
	vec2 m_position;
	vec2 m_scale;
	float m_facing; 
	
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	void debugUpdate();


	void debugDraw(const mat3 &T = mat3Identity()) const ;

	mat3 getLocalTransform() const; 

};