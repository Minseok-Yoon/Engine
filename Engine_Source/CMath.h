#pragma once

namespace ya::math
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2() :
			x(0.0f),
			y(0.0f)
		{}

		Vector2(float _x, float _y) :
			x(_x),
			y(_y)
		{}

		Vector2 operator+(Vector2 _vOther)
		{
			return Vector2(x + _vOther.x, y + _vOther.y);
		}

		Vector2 operator-(Vector2 _vOther)
		{
			return Vector2(x - _vOther.x, y - _vOther.y);
		}

		Vector2 operator/(float _fValue)
		{
			return Vector2(x / _fValue, y / _fValue);
		}
	};
}