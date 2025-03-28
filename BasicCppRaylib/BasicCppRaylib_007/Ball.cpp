#include "Ball.h"

#include "Consts.h"
#include "Paddle.h"

#include <cmath>

Ball::Ball() :
	BaseObject(),
	mRadius{ 10.0f },
	mColor{ BLUE },
	mSpeed{ 0.0f, 0.0f },
	mRadDirectionAngle{ 0.0f },
	mWallHitSound{ 0 },
	mPaddleHitSound{ 0 },
	mGoalSound{ 0 }
{
}

Ball::~Ball()
{
}

void Ball::Init()
{
	mPosition = Vector2{ Consts::Window::WIDTH / 2.0f - Consts::Ball::X_OFFSET, Consts::Window::HEIGHT / 2.0f };
	mRadius = Consts::Ball::RADIUS;
	mColor = Color{ Consts::Ball::COLOR[0], Consts::Ball::COLOR[1], Consts::Ball::COLOR[2], Consts::Ball::COLOR[3] };
	
	mRadDirectionAngle = PI / 4.0f;
	mSpeed = Vector2{ Consts::Ball::BASE_SPEED * std::cos(mRadDirectionAngle), Consts::Ball::BASE_SPEED * std::sin(mRadDirectionAngle) };
}

void Ball::SetSounds(const BallSounds& sounds)
{
	mWallHitSound = sounds.wallHit;
	mPaddleHitSound = sounds.paddleHit;
	mGoalSound = sounds.goal;
}

void Ball::HandlePaddleCollision(const Paddle& paddle, bool bIsLeftPaddle)
{
	if (CheckCollisionCircleRec(GetPosition(), GetRadius(), paddle.GetPaddleRectangle()))
	{
		float paddleMiddleY = paddle.GetPosition().y + paddle.GetHeight() / 2.0f;
		float collisionPointY = GetPosition().y;
		float relativeCollisionY = (collisionPointY - paddleMiddleY) / (paddle.GetHeight() / 2.0f);

		float newDirectionAngle = relativeCollisionY * (50.0f * (PI / 180.0f));

		if (!bIsLeftPaddle)
		{
			newDirectionAngle = PI - newDirectionAngle;
			SetSoundPan(mPaddleHitSound, 0.25f);
		}
		else
		{
			SetSoundPan(mPaddleHitSound, 0.75f);
		}

		SetDirectionAngleRad(newDirectionAngle);

		PlaySound(mPaddleHitSound);
	}
}

void Ball::Update()
{
	//MovingObject::Update();

	// Calculate speed components based on direction angle
	mSpeed.x = Consts::Ball::BASE_SPEED * std::cos(mRadDirectionAngle);
	mSpeed.y = Consts::Ball::BASE_SPEED * std::sin(mRadDirectionAngle);

	// Update position
	mPosition.x += mSpeed.x;
	mPosition.y += mSpeed.y;

	// Horizontal walls collision and avoid jittering when the ball was parallel to walls
	if (mPosition.y >= Consts::Window::HEIGHT - mRadius)
	{
		PlaySound(mWallHitSound);

		mPosition.y = Consts::Window::HEIGHT - mRadius;
		mRadDirectionAngle = -mRadDirectionAngle;

		if (std::abs(mSpeed.y) < 0.1f)
		{
			mSpeed.y = (mSpeed.y < 0 ? -1 : 1) * 0.1f;
		}
	}
	else if (mPosition.y <= mRadius)
	{
		PlaySound(mWallHitSound);

		mPosition.y = mRadius;
		mRadDirectionAngle = -mRadDirectionAngle;

		if (std::abs(mSpeed.y) < 0.1f)
		{
			mSpeed.y = (mSpeed.y < 0 ? -1 : 1) * 0.1f;
		}
	}
}

void Ball::Draw() const
{
	DrawTexture(*mMainTexture, mPosition.x - mRadius, mPosition.y - mRadius, WHITE);
}

float Ball::GetRadius() const
{
	return mRadius;
}

float Ball::GetDirectionAngleRad() const
{
	return mRadDirectionAngle;
}

void Ball::SetDirectionAngleRad(float angle)
{
	mRadDirectionAngle = angle;
}

void Ball::PlayGoalSound(bool bHasLeftScored) const
{
	bHasLeftScored ? SetSoundPan(mGoalSound, 0.25f) : SetSoundPan(mGoalSound, 0.75f);

	PlaySound(mGoalSound);
}
