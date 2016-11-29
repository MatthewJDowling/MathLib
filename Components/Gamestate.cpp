#include "Gamestate.h"
#include "CollisionInt.h"

#include <iostream>

void Gamestate::play()
{
	player.transform.m_position = vec2{ 45,10 };
	player.transform.m_facing = 1.57;

	rock[0].transform.m_position = vec2{ 550,300   };
	rock[1].transform.m_position = vec2{ 1500,300  };
	rock[2].transform.m_position = vec2{ 2000,300  };
	rock[3].transform.m_position = vec2{ 2860, 650 };

	spike[0].transform.m_position = vec2{ 1750, 150 };
	spike[1].transform.m_position = vec2{ 550,  100 };
	spike[2].transform.m_position = vec2{2300,  650 };

	plat[0].transform.m_position = vec2{ 25,-15 };//Platforms
	plat[1].transform.m_position = vec2{ 675, 105 };//
	plat[2].transform.m_position = vec2{ 2500, 175 };//
	plat[5].transform.m_position = vec2{ 2300, 600 };//

	
	plat[3].transform.m_position = vec2{ 25,385 };//Walls
	plat[4].transform.m_position = vec2{ 3000,675 };//
	plat[6].transform.m_position = vec2{ 1500,100000 };//			
	plat[3].transform.m_facing = -1.57f;
	plat[4].transform.m_facing = -1.57f;
	plat[6].transform.m_facing = -1.57f;
	
	

	grapple.timer = 0;
}

void Gamestate::update(float deltaTime)
{
 	player.update(deltaTime, *this, player);
	camera.update(deltaTime, *this);
	grapple.update(deltaTime, player.transform, player.rigidbody, *this);

	for (int i = 0; i < 6; i++)
	{
		plat[i].update(deltaTime, *this);
	}

	player.grounded = false;
	for (int i = 0; i < 7; i++)
	{
		PlayerPlatformCollision(player, plat[i]);
	}

	//std::cout << "player grounded? " << player.grounded << "\n";

	for (int i = 0; i < 4; i++)
	{
		rock[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 4; i++)
	{
		PlayerRockCollision(player, rock[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		rock[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 4; i++)
	{
		GrappleRockCollision(grapple, rock[i] , player);
	}
	
	for (int i = 0; i < 3; i++)
	{
		spike[i].update(deltaTime, *this);
	}

	for (int i = 0; i < 3; i++)
	{
		PlayerSpikeCollision(player, spike[i]);
		
	}


}

void Gamestate::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);
	grapple.draw(cam);

	for (int i = 0; i < 4; i++)
	{
		rock[i].draw(cam);
		
		
	}
	for (int i = 0; i < 7; i++)
	{
		plat[i].draw(cam);

	}
	for (int i = 0; i < 3; i++)
	{
		spike[i].draw(cam);

	}
}
