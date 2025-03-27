#pragma once
#include "MovingObject.h"

class Paddle : public MovingObject
{
public:
	Paddle();
	Paddle(Vector2 position, Vector2 speed, float width, float height, Color color);
	
	void Init(Vector2 position, Vector2 speed, float width, float height, Color color);

	void Draw() const;

	Rectangle GetPaddleRectangle() const;
	float GetWidth() const;
	float GetHeight() const;

protected:
	float mWidth;
	float mHeight;
	Color mColor;

};

