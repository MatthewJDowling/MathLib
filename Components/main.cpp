#include "sfwdraw.h"
#include "Gamestate.h"

#include <cstdio>

void main()
{
	const float H = 800;
	const float W = 800;
	sfw::initContext(W,H);
	
	Gamestate game;
	game.play();

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		game.update(dt);
		
		game.draw();
		

		
	}

	sfw::termContext();
}
