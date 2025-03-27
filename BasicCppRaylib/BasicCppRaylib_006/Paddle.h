#pragma once
#include "BaseObject.h"

struct PaddleInputs
{
	int upKey;
	int downKey;
};

class Paddle : public BaseObject
{
public:
	Paddle();

	void Init(Vector2 position, Vector2 speed, PaddleInputs inputs);

	inline void SetInputs(PaddleInputs inputs) { mInputs = inputs; }
	void ProcessInputs();

	void Update();

	void Draw() const;

	Rectangle GetPaddleRectangle() const;
	float GetWidth() const;
	float GetHeight() const;

protected:
	float mWidth;
	float mHeight;
	Color mColor;

	Vector2 mSpeed;
	PaddleInputs mInputs;

};

