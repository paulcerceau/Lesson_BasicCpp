#pragma once
#include "MovingObject.h"
#include "IRenderable.h"

class Paddle : public MovingObject, public IRenderable
{
public:
	Paddle();
	Paddle(Vector2 position, Vector2 speed, float width, float height, Color color);

	void Init(Vector2 position, Vector2 speed, float width, float height, Color color);

	void Draw() const override;

	Rectangle GetPaddleRectangle() const;
	float GetWidth() const;
	float GetHeight() const;

protected:
	float mWidth;
	float mHeight;
	Color mColor;

};

