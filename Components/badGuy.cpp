#include "badGuy.h"
#include "Gamestate.h"
BadGuy::BadGuy()
{
	vec2 hullvrts[] = { { 1,4 },{ 2,3 },{ 2,1 },{ 1,0 },{ -1,0 },{ -2,1 },{ -2,3 },{ -1,4 } };

	collider = Collider(hullvrts, 8);

	transform.m_scale = vec2{ 6,6 };

	badGuyMS = vec2 { 50,0 };

	transform.m_facing = 6.28;
}

void BadGuy::update(float deltaTime, Gamestate & gs)
{
	rigidbody.integrate(transform, deltaTime);

	
	
	rigidbody.addForce(vec2{ badGuyMS });

	if (turnNow == true)
	{
		badGuyMS *= -1; 
		transform.m_facing *= -1;
		turnNow = false; 
	}
	


}

void BadGuy::draw(const mat3 & camera)
{
	//Brown color code : 0x87694fff
	collider.DebugDraw(camera, transform);
	collider.color = RED;
}
