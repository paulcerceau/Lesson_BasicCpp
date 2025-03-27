#pragma once
#include "MovingObject.h"
#include "IRenderable.h"

class Paddle;

class Ball : public MovingObject, public IRenderable
{
public:
	Ball();

	void Init();

	void HandlePaddleCollision(const Paddle& paddle, bool bIsLeftPaddle);

	void Update();

	void Draw() const override;

	float GetRadius() const;

	float GetDirectionAngleRad() const;
	void SetDirectionAngleRad(float angle);

protected:
	float mRadius;
	Color mColor;
	float mRadDirectionAngle;

};
