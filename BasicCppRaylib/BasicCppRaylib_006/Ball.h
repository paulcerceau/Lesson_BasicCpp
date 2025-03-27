#pragma once
#include "MovingObject.h"
#include "IRenderable.h"

class Ball : public MovingObject, public IRenderable
{
public:
	Ball();
	Ball(Vector2 position, Vector2 speed, float radius, Color color);

	void Init(Vector2 position, Vector2 speed, float radius, Color color);

	void Draw() const override;

	float GetRadius() const;

protected:
	float mRadius;
	Color mColor;

};
