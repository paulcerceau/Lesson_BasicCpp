#include "Consts.h"

namespace Consts
{
	namespace Maths
	{
		const float EPSILON{ 0.01f };
	}

	namespace Window
	{
		const int WIDTH{ 800 }; 
		const int HEIGHT{ 450 }; 
		const char* NAME{ "Basic C++ with Raylib" }; 
	}

	namespace Ball
	{
		const float RADIUS{ 10.0f };
		const unsigned char COLOR[4]{ 0, 121, 241, 255 };
		const float X_OFFSET{ 200.0f }; 
		const float BASE_SPEED{ 6.0f }; 
	}

	namespace Paddle
	{
		const float BASE_WIDTH{ 10.0f }; 
		const float BASE_HEIGHT{ 100.0f }; 
		const unsigned char COLOR[4]{ 0, 82, 172, 255 };
		const float BASE_SPEED{ 6.0f }; 
		const float DECELERATION_FACTOR{ 0.95f }; 
	}

	namespace Score
	{
		const int WINNING_SCORE{ 10 }; 
		const float TEXT_SIZE{ 50.0f }; 
	}
}
