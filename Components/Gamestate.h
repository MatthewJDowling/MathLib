#pragma once
#include "Player.h"
#include "camera.h"

class Gamestate
{

public: 
	PlayerShip player;

	Camera camera; 

	void play();
	void update(float deltaTime);
	void draw();
};