#include "Spike.h"

Spike::Spike()
{
	vec2 hullvrts[] = { {0,0},{2,3},{4,0}};

	collider = Collider(hullvrts, 3);

	transform.m_scale = vec2{ 8,8 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Spike::update(float deltaTime, Gamestate & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Spike::draw(const mat3 & camera)
{
	//Brown color code : 0x87694fff
	collider.DebugDraw(camera, transform);

}
