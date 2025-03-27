#pragma once
#include "raylib.h"

class BaseObject
{
public:
	BaseObject();
	BaseObject(Vector2 position);
	virtual ~BaseObject();

	virtual void Update() = 0;
	virtual void Draw() const = 0;

	inline Vector2 GetPosition() const { return mPosition; }
	inline void SetPosition(Vector2 position) { mPosition = position; }

protected:
	Vector2 mPosition;

};

