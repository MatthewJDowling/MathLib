#pragma once
#include "Rock.h"
#include "Player.h"
#include "Platform.h"
#include "Grapple.h"
#include "Spike.h"

void PlayerPlatformCollision(PlayerShip &player, Platform plat);

void PlayerRockCollision(PlayerShip & player, Rock a_rock);

void GrappleRockCollision(Grapple & a_grapple, Rock & a_rock, PlayerShip player);

void PlayerSpikeCollision(PlayerShip & player, Spike a_spike);

