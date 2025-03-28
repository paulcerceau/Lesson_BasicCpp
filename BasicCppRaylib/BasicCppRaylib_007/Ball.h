#pragma once
#include "BaseObject.h"

class Paddle;

struct BallSounds
{
	Sound* wallHit;
	Sound* paddleHit;
	Sound* goal;
};

class Ball : public BaseObject
{
public:
	Ball();
	~Ball() override;

	void Init();

	void SetSounds(const BallSounds& sounds);

	void HandlePaddleCollision(const Paddle& paddle, bool bIsLeftPaddle);

	void Update();

	void Draw() const override;

	float GetRadius() const;

	float GetDirectionAngleRad() const;
	void SetDirectionAngleRad(float angle);

	void PlayGoalSound(bool bHasLeftScored) const;

protected:
	float mRadius;
	Color mColor;

	Vector2 mSpeed;
	float mRadDirectionAngle;

	Sound* mWallHitSound;
	Sound* mPaddleHitSound;
	Sound* mGoalSound;

};
