#pragma once
#include "Player.h"
#include "camera.h"
#include "Rock.h"
#include "Platform.h"
#include "CollisionInt.h"
#include "Grapple.h"

class Gamestate
{

public: 
	PlayerShip player;
	Camera camera; 
	Rock rock[2];
	Platform plat[2];
	Grapple grapple; 

	void play();
	void update(float deltaTime);
	void draw();
};