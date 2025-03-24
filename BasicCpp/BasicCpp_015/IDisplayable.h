#pragma once

class IDisplayable
{
public:
	virtual ~IDisplayable() {}

	virtual void Display() const = 0;

};
