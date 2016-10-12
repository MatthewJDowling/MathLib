#include "Transform.h"
#include "sfwdraw.h"



Transform::Transform(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	m_scale = { 12,12 };
	m_facing = 0;
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

void Transform::debugDraw() const 
{
	sfw::drawCircle(m_position.x, m_position.y, 12,12, RED);

	mat3 L = getLocalTransform();

	vec3 pos = vec3{ m_position.x, m_position.y,0 };
	vec3 right = pos + L * vec3{ 7,0,0 };
	vec3 up =    pos + L * vec3{ 0,7,0 };

	//vec2 dirEnd = m_position + getDirection() * m_scale.x * 60;
	//vec2 upEnd = m_position + perp(getDirection()) *m_scale.y * 45;


	sfw::drawLine(m_position.x, m_position.y, right.x, right.y, CYAN);
	sfw::drawLine(m_position.x, m_position.y, up.x, up.y, GREEN);
}

