#pragma once
#include "Rock.h"
#include "Player.h"
#include "Platform.h"

void PlayerPlatformCollision(PlayerShip &player, Platform plat);

void PlayerRockCollision(PlayerShip & player, Rock a_rock);

bool playerTouch(PlayerShip &player);

