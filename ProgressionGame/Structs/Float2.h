#pragma once

class Float2
{
public:

	Float2();
	Float2(float x, float y);

	~Float2();
	Float2(const Float2& other);
	Float2& operator=(const Float2& other);
	Float2(Float2&& other);
	Float2& operator=(Float2&& other);

	float X;
	float Y;
};