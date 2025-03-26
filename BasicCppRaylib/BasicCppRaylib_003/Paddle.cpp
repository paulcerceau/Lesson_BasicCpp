#include "Paddle.h"

Paddle::Paddle() : 
	MovingObject{  },
	mWidth{ 0.0f },
	mHeight{ 0.0f },
	mColor{ WHITE }
{
}


Paddle::Paddle(Vector2 position, Vector2 speed, float width, float height, Color color) :
	MovingObject{ position, speed },
	mWidth{ width },
	mHeight{ height },
	mColor{ color }
{
}

void Paddle::Init(Vector2 position, Vector2 speed, float width, float height, Color color)
{
	MovingObject::Init(position, speed);
	mWidth = width;
	mHeight = height;
	mColor = color;
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
