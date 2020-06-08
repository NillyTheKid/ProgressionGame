#include "Float2.h"

Float2::Float2()
	:X{ 0 }, Y{ 0 }
{
}

Float2::Float2(float x, float y)
	: X{ x }, Y{ y }
{
}

Float2::~Float2()
{
}

Float2::Float2(const Float2& other)
{
	X = other.X;
	Y = other.Y;
}

Float2& Float2::operator=(const Float2& other)
{
	this->X = other.X;
	this->Y = other.Y;
	return *this;
}

Float2::Float2(Float2&& other)
{
	X = other.X;
	Y = other.Y;
}

Float2& Float2::operator=(Float2&& other)
{
	this->X = other.X;
	this->Y = other.Y;
	return *this;
}
