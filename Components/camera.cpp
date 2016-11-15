#include "camera.h"
#include "Gamestate.h"

Camera::Camera()
{
	projection = translate(600, 600) * scale(2, 2);
}

mat3 Camera::getCameraMatrix()
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState &gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}
