#include "sfwdraw.h"
#include "flops.h"
#include "vec2.h"
#include "Transform.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
#include "SpaceshipController.h"
#include "SpaceShipRenderer.h"
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "shapeDraw.h"



void main()
{
	const float H = 800;
	const float W = 800;
	sfw::initContext(W,H);
	
	

	Transform playerTransform(300,300);
	Transform sunTransform(0,0,20,YELLOW);
	Transform plan1(0,0,10,GREEN);
	Transform moon1(0,0,6,WHITE);


	//Player
	Rigidbody playerRigidbody;
	Rigidbody sunRbody;
	Rigidbody plan1RB;
	Rigidbody moon1RB;

	PlanetaryMotor sunMotor;
	PlanetaryMotor plan1Motor;
	PlanetaryMotor moon1motor;


	plan1.m_parent = &sunTransform;
	moon1.m_parent = &plan1;


	playerRigidbody.velocity = vec2{ 0,0 };
	SpaceShipLocomotion playerLoco;
	SpaceshipRenderer playerRender;
	SpaceshipController playerCtrl;

	//Sun
	sunMotor.m_rotationSpeed = 2;
	sunTransform.m_position = vec2{ H / 2 , W / 2 };
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//Planet
	plan1.m_position = vec2{ 500,0 };
	plan1Motor.m_rotationSpeed = 2;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	//Moon
	moon1.m_position = vec2{ 501, 0 };
	moon1motor.m_rotationSpeed = 2;
	moon1.size;
	PlanetaryRenderer moon1renderer(WHITE, 7);

	Transform cameraTransform;

	playerTransform.color = CYAN;
	playerTransform.m_scale = { 15, 15 };

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();

		// update
		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);

		sunMotor.update(sunRbody);
		plan1Motor.update(plan1RB);
		moon1motor.update(moon1RB);

		playerRigidbody.integrate(playerTransform, deltaTime);
		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);


		// draw

		// CAMERA
		cameraTransform.m_position = lerp(
			cameraTransform.m_position,
			(playerTransform.getGlobalPosition()),// + sunTransform.getGlobalPosition()) / 2,
			1);

		mat3 proj = translate(W/2, H/2) * scale(1, 1);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view; 
		
	
		// OBJECTS
		//playerTransform.debugDraw(camera);
		//sunTransform.debugDraw(camera);
		//plan1.debugDraw(camera);
		//moon1.debugDraw(camera);
		//cameraTransform.debugDraw(camera);

		//playerRigidbody.debugDraw(camera, playerTransform);

		sunRenderer.draw(camera, sunTransform);
		plan1renderer.draw(camera, plan1);
		moon1renderer.draw(camera, moon1);

		playerRender.draw(camera, playerTransform);

		drawAABB(camera * playerTransform.getGlobalTransform() * AABB { 0, 3, 0, 3 }, RED);
	}

	sfw::termContext();
}
