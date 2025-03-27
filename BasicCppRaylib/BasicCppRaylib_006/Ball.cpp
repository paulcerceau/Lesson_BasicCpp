#include "Ball.h"

#include "Consts.h"


Ball::Ball() :
	MovingObject(),
	mRadius{ 10.0f },
	mColor{ BLUE }
{

}

void Ball::Init()
{
	Vector2 startPosition{ Consts::Window::WIDTH / 2.0f - Consts::Ball::X_OFFSET, Consts::Window::HEIGHT / 2.0f };
	Vector2 speed{ Consts::Ball::BASE_SPEED, Consts::Ball::BASE_SPEED };

	MovingObject::Init(startPosition, speed);
	mRadius = Consts::Ball::RADIUS;
	mColor = Color{ Consts::Ball::COLOR[0], Consts::Ball::COLOR[1], Consts::Ball::COLOR[2], Consts::Ball::COLOR[3] };
}

void Ball::Draw() const
{
	DrawCircle(mPosition.x, mPosition.y, mRadius, mColor);
}

float Ball::GetRadius() const
{
	return mRadius;
}
