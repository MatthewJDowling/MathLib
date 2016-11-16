#include "camera.h"
#include "Gamestate.h"

Camera::Camera()
{
	projection = translate(400, 400) * scale(1, 1);
}

mat3 Camera::getCameraMatrix()
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, Gamestate &gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();
}
