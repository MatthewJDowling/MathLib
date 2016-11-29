#pragma once
#include "Player.h"
#include "camera.h"
#include "Rock.h"
#include "Platform.h"
#include "CollisionInt.h"
#include "Grapple.h"
#include "Spike.h"


class Gamestate
{

public: 
	PlayerShip player;
	Camera camera; 
	Rock rock[4];
	Platform plat[7];
	Spike spike[3];

	Grapple grapple; 
	

	void play();
	void update(float deltaTime);
	void draw();
};