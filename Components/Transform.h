#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "mat3.h"
#include "cmath"
class Transform
{
public:
	//Transform();
	Transform(float x = 0, float y = 0, int a_size = 0, unsigned int a_color = 0);
	vec2 m_position;
	vec2 m_scale;
	float m_facing; 
	unsigned int color;
	int size;
	Transform *m_parent;
	
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);
	vec2 Transform::getGlobalPosition() const;
	vec2 Transform::getGlobalRight() const;
	vec2 Transform::getGlobalUp() const;
	float Transform::getGlobalAngle() const;


	void debugUpdate();


	void debugDraw(const mat3 &T = mat3Identity()) const ;

	mat3 getLocalTransform() const; 
	mat3 getGlobalTransform() const; 


};