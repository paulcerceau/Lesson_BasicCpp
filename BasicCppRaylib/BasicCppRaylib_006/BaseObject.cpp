#include "BaseObject.h"

BaseObject::BaseObject() :
	mPosition{ Vector2 { 0.0f, 0.0f} }
{
}

BaseObject::BaseObject(Vector2 position) :
	mPosition{ position }
{
}

BaseObject::~BaseObject()
{
}
