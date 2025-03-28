#include "Paddle.h"

#include <cmath>

#include "Consts.h"


Paddle::Paddle() :
	BaseObject{  },
	mWidth{ 0.0f },
	mHeight{ 0.0f },
	mColor{ WHITE },
	mSpeed{ 0.0f, 0.0f },
	mInputs{ PaddleInputs{ 265, 264 } }
{
}

Paddle::~Paddle()
{
}

void Paddle::Init(Vector2 position, Vector2 speed, PaddleInputs inputs)
{
	mPosition = position;
	mSpeed = speed;
	mInputs = inputs;
	mWidth = Consts::Paddle::BASE_WIDTH;
	mHeight = Consts::Paddle::BASE_HEIGHT;
	mColor = Color{ Consts::Paddle::COLOR[0], Consts::Paddle::COLOR[1], Consts::Paddle::COLOR[2], Consts::Paddle::COLOR[3] };
}

void Paddle::ProcessInputs()
{
	if (IsKeyDown(mInputs.upKey))
	{
		mSpeed = Vector2{ 0.0f, -Consts::Paddle::BASE_SPEED };
	}
	else if (IsKeyDown(mInputs.downKey))
	{
		mSpeed = Vector2{ 0.0f, Consts::Paddle::BASE_SPEED };
	}
}

void Paddle::Update()
{
	mPosition.x += mSpeed.x;
	mPosition.y += mSpeed.y;

	//v Movement (must be last) ======================================
	// Deceleration
	if (mSpeed.y == 0.0f)
	{
		// No need to continue as the paddle is not moving
		return; 
	}
    else if (std::abs(mSpeed.y) < Consts::Maths::EPSILON)
    {
		mSpeed.y = 0.0f;
    }
    else
    {
		mSpeed.y *= Consts::Paddle::DECELERATION_FACTOR;
    }

	// Check if the paddle is at the top or bottom of the screen and
	// reset its position if that's the case
	if (mPosition.y <= 0)
	{
		mPosition = Vector2{ mPosition.x, 0 };
	}
	else if (mPosition.y + mHeight >= Consts::Window::HEIGHT)
	{
		mPosition = Vector2{ mPosition.x, Consts::Window::HEIGHT - mHeight };
	}

	//^ Movement =====================================================
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

