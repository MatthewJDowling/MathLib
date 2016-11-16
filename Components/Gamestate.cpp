#include "Gamestate.h"
#include "CollisionInt.h"
void Gamestate::play()
{
	player.transform.m_position = vec2{ 45,5 };
	player.transform.m_facing = 90;

	rock[0].transform.m_position = vec2{ 200,200 };
	rock[1].transform.m_position = vec2{ 800,200 };

	plat[0].transform.m_position = vec2{ 25,-15 };
	plat[1].transform.m_position = vec2{ 700,-15 };
}

void Gamestate::update(float deltaTime)
{
	player.update(deltaTime, *this, player);
	camera.update(deltaTime, *this);

	for (int i = 0; i < 2; i++)
	{
		plat[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 2; i++)
	{
		PlayerPlatformCollision(player, plat[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		rock[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 2; i++)
	{
		PlayerRockCollision(player, rock[i]);
	}
}

void Gamestate::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);

	for (int i = 0; i < 2; i++)
	{
		rock[i].draw(cam);
		plat[i].draw(cam);
	}
}
