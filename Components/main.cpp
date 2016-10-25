#include "sfwdraw.h"
#include "flops.h"
#include "vec2.h"
#include "Transform.h"
#include "RigidBody.h"
#include "spaceShipLocomotion.h"
#include "SpaceshipController.h"

#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"



void main()
{
	float H = 800;
	float W = 800;
	sfw::initContext(W,H);
	
	SpaceshipController spacectrl('A', 'W', 'D', 'S', ' ');

	Transform playerTransform(400,400);
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

	//Sun
	sunMotor.m_rotationSpeed = 2;
	sunTransform.m_position = vec2{ H / 2 , W / 2 };
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//Planet
	plan1.m_position = vec2{ 10,0 };
	plan1Motor.m_rotationSpeed = 4;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	//Moon
	moon1.m_position = vec2{ .25, 0 };
	moon1motor.m_rotationSpeed = 4;
	moon1.size;
	PlanetaryRenderer moon1renderer(WHITE, 7);



	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		//
		playerRigidbody.integrate(playerTransform, deltaTime);
		spacectrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody, deltaTime);
		//
		sunMotor.update(sunRbody);
		plan1Motor.update(plan1RB);
		moon1motor.update(moon1RB);


		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);
		
		
		
		
		
		
		playerTransform.debugDraw();
		sunTransform.debugDraw();
		plan1.debugDraw();
		moon1.debugDraw();
		//playerRigidbody.debugDraw(playerTransform);
		
	}
	sfw::termContext();
}
