#pragma once
#include "BaseObject.h"

class Paddle;

class Ball : public BaseObject
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

	Vector2 mSpeed;
	float mRadDirectionAngle;

};
