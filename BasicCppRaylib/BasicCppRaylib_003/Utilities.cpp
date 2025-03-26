#include "Utilities.h"

namespace Utils
{
	void DrawCenteredText(const char* text, int fontSize, Color color)
	{
		int textSize = MeasureText(text, fontSize);
		Vector2 centeredPosition = { GetScreenWidth() / 2 - textSize / 2, GetScreenHeight() / 2 };
		DrawText(text, centeredPosition.x, centeredPosition.y, fontSize, color);
	}

	void DrawCenteredTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color color)
	{
		Vector2 textSize = MeasureTextEx(font, text, fontSize, spacing);
		Vector2 centeredPosition = { position.x - textSize.x / 2, position.y - textSize.y / 2 };
		DrawTextEx(font, text, centeredPosition, fontSize, spacing, color);
	}

}

