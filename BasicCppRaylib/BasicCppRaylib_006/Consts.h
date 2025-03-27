#pragma once

namespace Consts
{
	namespace Window
	{
		const int WIDTH = 800;
		const int HEIGHT = 450;
		const char* NAME = "Basic C++ with Raylib";
	}
	
	namespace Ball
	{
		const float X_OFFSET = 200.0f;
		const float BASE_SPEED = 4.0f;
	}
	
	namespace Paddle
	{
		const float BASE_WIDTH = 10.0f;
		const float BASE_HEIGHT = 100.0f;
		const float MAX_SPEED = 6.0f;
		const float DECELERATION_FACTOR = 0.95f;
	}

	namespace Score
	{
		const int WINNING_SCORE = 10;
		const float TEXT_SIZE = 50.0f;
	}
}