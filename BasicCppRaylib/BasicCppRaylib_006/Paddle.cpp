#include "Paddle.h"

#include "Consts.h"


Paddle::Paddle() :
	MovingObject{  },
	mWidth{ 0.0f },
	mHeight{ 0.0f },
	mColor{ WHITE },
	mInputs{ PaddleInputs{ 265, 264 } }
{
}

void Paddle::Init(Vector2 position, Vector2 speed, PaddleInputs inputs)
{
	MovingObject::Init(position, speed);
	mInputs = inputs;
	mWidth = Consts::Paddle::BASE_WIDTH;
	mHeight = Consts::Paddle::BASE_HEIGHT;
	mColor = Color{ Consts::Paddle::COLOR[0], Consts::Paddle::COLOR[1], Consts::Paddle::COLOR[2], Consts::Paddle::COLOR[3] };
}

void Paddle::ProcessInputs()
{
	if (IsKeyDown(mInputs.upKey))
	{
		mSpeed = Vector2{ 0.0f, -Consts::Paddle::MAX_SPEED };
	}
	else if (IsKeyDown(mInputs.downKey))
	{
		mSpeed = Vector2{ 0.0f, Consts::Paddle::MAX_SPEED };
	}
	else
	{
		mSpeed = Vector2{ 0.0f, mSpeed.y * Consts::Paddle::DECELERATION_FACTOR };
	}
}

void Paddle::Draw() const
{
	DrawRectangle(mPosition.x, mPosition.y, mWidth, mHeight, mColor);
}

Rectangle Paddle::GetPaddleRectangle() const
{
	return Rectangle{ mPosition.x, mPosition.y, mWidth, mHeight };
}

float Paddle::GetWidth() const
{
	return mWidth;
}

float Paddle::GetHeight() const
{
	return mHeight;
}
