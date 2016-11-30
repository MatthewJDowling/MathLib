#include "Grapple.h"
#include "Player.h"
Grapple::Grapple()
{
	vec2 hullvrts[] = { {0,0},{5,5} };

	collider = Collider(hullvrts, 2);

	transform.m_scale = vec2{ 8,8 };
	
	rigidbody.mass = 1;
}

void Grapple::update(float deltaTime, Transform &target_trans, Rigidbody &target_rbody, Gamestate &gs)
{
	timer -= deltaTime;
	isAlive = timer > 0; 

	if (!isAlive) return;
	rigidbody.integrate(transform, deltaTime);

	if (isAttached == true)
	{
		vec2 dir = normal(transform.getGlobalPosition() - target_trans.getGlobalPosition());

		target_rbody.addForce(dir * 36000);

		if (magnitude(transform.getGlobalPosition() - target_trans.getGlobalPosition()) < 80)
		{
			isAttached = false;
			timer = 0;
		}
	}
}

void Grapple::draw(const mat3 & camera)
{
	if (!isAlive) return;
	
	//transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	//rigidbody.debugDraw(camera, transform);
	collider.color = GREEN; 
}
