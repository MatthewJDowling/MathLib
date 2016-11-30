#include "winFlag.h"

Flag::Flag()
{
	vec2 hullvrts[] = { { 0,0 },{ 4,0 },{ 4,10 }, {0,10} };

	collider = Collider(hullvrts, 4);

	transform.m_scale = vec2{ 8,8 };
}

void Flag::update(float deltaTime, Gamestate & gs)
{
}

void Flag::draw(const mat3 & camera)
{
	collider.DebugDraw(camera, transform);
	collider.color = GREEN;
}
