#pragma once

namespace Consts
{
	namespace Maths
	{
		extern const float EPSILON;
	}

	namespace Window
	{
		extern const int WIDTH;
		extern const int HEIGHT;
		extern const char* NAME;
	}

	namespace Ball
	{
		extern const float RADIUS;
		extern const unsigned char COLOR[4];
		extern const float X_OFFSET;
		extern const float BASE_SPEED;
	}

	namespace Paddle
	{
		extern const float BASE_WIDTH;
		extern const float BASE_HEIGHT;
		extern const unsigned char COLOR[4];
		extern const float BASE_SPEED;
		extern const float DECELERATION_FACTOR;
	}

	namespace Score
	{
		extern const int WINNING_SCORE;
		extern const float TEXT_SIZE;
	}
}
