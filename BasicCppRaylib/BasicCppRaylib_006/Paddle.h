#pragma once
#include "MovingObject.h"
#include "IRenderable.h"

struct PaddleInputs
{
	int upKey;
	int downKey;
};

class Paddle : public MovingObject, public IRenderable
{
public:
	Paddle();
	Paddle(Vector2 position, Vector2 speed, float width, float height, Color color);

	void Init(Vector2 position, Vector2 speed, float width, float height, Color color);

	inline void SetInputs(PaddleInputs inputs) { mInputs = inputs; }
	void ManageInputs();

	void Draw() const override;

	Rectangle GetPaddleRectangle() const;
	float GetWidth() const;
	float GetHeight() const;

protected:
	float mWidth;
	float mHeight;
	Color mColor;

	float mDecelerationFactor;

	PaddleInputs mInputs;
};

