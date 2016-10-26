#include "Transform.h"
#include "sfwdraw.h"
#include "shapeDraw.h"



Transform::Transform(float x, float y, int a_size, unsigned int a_color)
{
	m_position.x = x;
	m_position.y = y;

	size = a_size;

	m_scale = { 1, 1 };
	m_facing = 0;
	color = a_color;
	m_parent = nullptr;
}

vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotate(m_facing);

		return T * S * R;
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}


vec2 Transform::getGlobalRight() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	return angle(getGlobalRight());
}

void Transform::debugUpdate()
{
	if (m_position.x < 0)
	{
		m_position.x = 800; 
	}
	else if (m_position.x > 800)
	{
		m_position.x = 0;
	}

	if (m_position.y < 0)
	{
		m_position.y = 800;
	}
	else if (m_position.y > 800)
	{
		m_position.y = 0;
	}
}

void Transform::debugDraw(const mat3 &T) const 
{
	

	mat3 L = T * getGlobalTransform();

	vec3 pos = L[2];
	vec3 sgp = m_parent ? m_parent->getGlobalTransform()[2] : pos;

	vec3 up =  L * vec3{ 7,0,1 };
	vec3 right =     L * vec3{ 0,7,1 };

	


	drawCircle(L * Circle{ 0,0, 5 }, 0x88888FF);
	sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);
	sfw::drawCircle(pos.x, pos.y, size, 12, color);
	drawAABB(AABB{ 0,0,10,10 },RED);
}

