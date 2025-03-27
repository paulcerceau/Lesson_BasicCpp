#pragma once
#include "MovingObject.h"
#include "IRenderable.h"

class Ball : public MovingObject, public IRenderable
{
public:
	Ball();

	void Init();

	void Draw() const override;

	float GetRadius() const;

protected:
	float mRadius;
	Color mColor;

};
