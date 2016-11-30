#include "Gamestate.h"
#include "CollisionInt.h"

#include <iostream>

void Gamestate::play()
{
	//Player
	player.transform.m_position = vec2{ 45,10 };
	player.transform.m_facing = 1.57;

	//Rocks

	rock[0].transform.m_position = vec2{ 550,300   };
	rock[1].transform.m_position = vec2{ 1500,300  };
	rock[2].transform.m_position = vec2{ 2000,300  };
	rock[3].transform.m_position = vec2{ 2860, 650 };

	// Bad Guys 

	badguy[0].transform.m_position = vec2{ 2700, 600 };
	badguy[1].transform.m_position = vec2{200,-15};
	badguy[2].transform.m_position = vec2{2600, 175};
	

	//Spikes

	spike[0].transform.m_position = vec2{ 1750, 150};//1750,150
	spike[1].transform.m_position = vec2{ 675, 25};//600,40
	spike[2].transform.m_position = vec2{2900,  500 };//2900, 500
	spike[2].transform.m_facing = 1.57f;
	spike[1].transform.m_facing = 1.57f;
	spike[0].transform.m_facing = 0;

	//Platforms

	plat[0].transform.m_position = vec2{ 25,-15 };
	plat[1].transform.m_position = vec2{ 675, 105 };
	plat[2].transform.m_position = vec2{ 2500, 175 };
	plat[5].transform.m_position = vec2{ 2300, 600 };

	//Walls

	plat[3].transform.m_position = vec2{ 25,385 };
	plat[4].transform.m_position = vec2{ 3000,675 };
	plat[6].transform.m_position = vec2{ 1500,100000 };		
	plat[3].transform.m_facing = -1.57f;
	plat[4].transform.m_facing = -1.57f;
	plat[6].transform.m_facing = -1.57f;

	//
	barrier[0].transform.m_position = vec2{ 25,-15   };
	barrier[1].transform.m_position = vec2{ 515,-15   }; //515 440
	
	barrier[2].transform.m_position = vec2{ 675,105  };
	barrier[3].transform.m_position = vec2{ 1175,105  };

	barrier[4].transform.m_position = vec2{ 2500,90 };
	barrier[5].transform.m_position = vec2{ 2900,175 };

	barrier[6].transform.m_position = vec2{ 2300,600 };
	barrier[7].transform.m_position = vec2{ 2800,600 };

	flag.transform.m_position = vec2{2300,600};
	

	grapple.timer = 0;
}

void Gamestate::update(float deltaTime)
{

	/*system("cls");
	printf("%f", player.rigidbody.force.x);*/


 	player.update(deltaTime, *this, player);
	camera.update(deltaTime, *this);
	grapple.update(deltaTime, player.transform, player.rigidbody, *this);
	flag.update(deltaTime, *this);

	for (int i = 0; i < 6; i++)
	{
		plat[i].update(deltaTime, *this);
	}

	player.grounded = false;
	

	

	for (int i = 0; i < 4; i++)
	{
		rock[i].update(deltaTime, *this);
	}

	
	for (int i = 0; i < 4; i++)
	{
		rock[i].update(deltaTime, *this);
	}


	for (int i = 0; i < 3; i++)
	{
		spike[i].update(deltaTime, *this);
	}
	for (int i = 0; i < 3; i++)
	{
		badguy[i].update(deltaTime, *this);
	}
	for (int i = 0; i < 8; i++)
	{
		barrier[i].update(deltaTime, *this);
	}
	for (int i = 0; i < 7; i++)
	{
		PlayerPlatformCollision(player, plat[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		PlayerRockCollision(player, rock[i]);
	}


	for (int i = 0; i < 4; i++)
	{
		GrappleRockCollision(grapple, rock[i] , player);
	}
	


	for (int i = 0; i < 3; i++)
	{
		PlayerSpikeCollision(player, spike[i]);
		
	}

	for(int j = 0; j < 3; j++)
		for(int i = 0; i < 8; i++)
		{
			BadGuyBarrierCollision(badguy[j], barrier[i]);
		}
	for (int i = 0; i < 3; i++)
	{
		playerBadGuyCollision(player, badguy[i]);

	}
	for (int i = 0; i < 1; i++)
	{
		playerFlagCollision(player, flag);

	}

}

void Gamestate::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);
	grapple.draw(cam);
	flag.draw(cam);

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
	for (int i = 0; i < 3; i++)
	{
		badguy[i].draw(cam);

	}

	/*for (int i = 0; i < 8; i++)
	{
		barrier[i].draw(cam);

	}*/
}
