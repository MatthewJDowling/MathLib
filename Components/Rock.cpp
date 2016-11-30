#include "Rock.h"

Rock::Rock()
{
	vec2 hullvrts[] = {{1,4 },{2,3},{2,1},{1,0},{-1,0},{-2,1},{-2,3},{-1,4}};

	collider = Collider(hullvrts, 8);

	transform.m_scale = vec2{ 8,8 };
	rigidbody.drag = 0.0f; 
	rigidbody.angularDrag = 0.0f; 
	rigidbody.mass = 10;
}

void Rock::update(float deltaTime, Gamestate & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Rock::draw(const mat3 & camera)
{
	//Brown color code : 0x87694fff
	collider.DebugDraw(camera, transform);
	collider.color = 0x87694fff;
}
