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

	void Init(Vector2 position, Vector2 speed, PaddleInputs inputs);

	inline void SetInputs(PaddleInputs inputs) { mInputs = inputs; }
	void ProcessInputs();

	void Draw() const override;

	Rectangle GetPaddleRectangle() const;
	float GetWidth() const;
	float GetHeight() const;

protected:
	float mWidth;
	float mHeight;
	Color mColor;

	PaddleInputs mInputs;
};

