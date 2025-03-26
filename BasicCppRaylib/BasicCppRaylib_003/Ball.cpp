#include "Ball.h"

Ball::Ball() :
	MovingObject(),
	mRadius{ 10.0f },
	mColor{ DARKBLUE }
{

}

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color) :
	MovingObject(position, speed),
	mRadius{ radius },
	mColor{ color }
{
}

void Ball::Init(Vector2 position, Vector2 speed, float radius, Color color)
{
	MovingObject::Init(position, speed);
	mRadius = radius;
	mColor = color;
}

void Ball::Draw() const
{
	DrawCircle(mPosition.x, mPosition.y, mRadius, mColor);
}
