#pragma once

#include "raylib.h"

namespace Utils 
{
	// Draw a centered text based on raylib's DrawText()
	void DrawCenteredText(const char* text, int fontSize, Color color);
    
	// Draw a centered text based on raylib's DrawTextEx()
    void DrawCenteredTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color color);

}