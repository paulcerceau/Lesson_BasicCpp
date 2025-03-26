#pragma once

#include "raylib.h"


class MovingObject
{
public:
	MovingObject();
	MovingObject(Vector2 position, Vector2 speed);
	~MovingObject();

	Vector2 GetPosition() const;
	void SetPosition(Vector2 position);
	
	Vector2 GetSpeed() const;
	void SetSpeed(Vector2 speed);

	void Init(Vector2 position, Vector2 speed);
	void Update();

protected:
	Vector2 mPosition;
	Vector2 mSpeed;

};