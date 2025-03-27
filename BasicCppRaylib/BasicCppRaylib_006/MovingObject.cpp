#include "MovingObject.h"


MovingObject::MovingObject() :
	mPosition{ Vector2 { 50.0f, 50.0f} },
	mSpeed{ Vector2 { 1.0f, 1.0f} }
{
}

MovingObject::MovingObject(Vector2 position, Vector2 speed) :
	mPosition{ position },
	mSpeed{ speed }
{
}

MovingObject::~MovingObject()
{
}

Vector2 MovingObject::GetPosition() const
{
	return mPosition;
}

void MovingObject::SetPosition(Vector2 position)
{
	mPosition = position;
}

Vector2 MovingObject::GetSpeed() const
{
	return mSpeed;
}

void MovingObject::SetSpeed(Vector2 speed)
{
	mSpeed = speed;
}

void MovingObject::SetMaxSpeed(float maxSpeed)
{
	mMaxSpeed = maxSpeed;
}

void MovingObject::Init(Vector2 position, Vector2 speed)
{
	mPosition = position;
	mSpeed = speed;
}

void MovingObject::Update()
{
	mPosition.x += mSpeed.x;
	mPosition.y += mSpeed.y;

}
