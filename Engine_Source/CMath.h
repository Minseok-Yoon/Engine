#pragma once
#include <cmath>

namespace ya::math
{
#define PI 3.141592f

	static float ConvertDegree(float _fRadian) { return (_fRadian * (180 / PI)); }
	
	struct Vector2
	{
		Vector2 Rotate(Vector2 _vVector, float _fDegree)
		{
			float radian = (_fDegree / 180.0f) * PI;
			_vVector.normalize();
			float x = cosf(radian) * _vVector.x - sinf(radian) * _vVector.y;
			float y = sinf(radian) * _vVector.x + cosf(radian) * _vVector.y;

			return Vector2(x, y);
		}

		float Dot(Vector2& _v1, Vector2& _v2)
		{
			return _v1.x * _v2.x + _v1.y * _v2.y;
		}

		float Cress(Vector2 _v1, Vector2 _v2)
		{
			return _v1.x * _v2.y + _v1.y * _v2.x;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

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

		void operator+=(Vector2 _vOther)
		{
			x += _vOther.x;
			y += _vOther.y;
		}

		Vector2 operator-(Vector2 _vOther)
		{
			return Vector2(x - _vOther.x, y - _vOther.y);
		}

		Vector2 operator*(float _fValue)
		{
			return Vector2(x * _fValue, y * _fValue);
		}

		Vector2 operator*(Vector2 _vV)
		{
			return Vector2(x * _vV.x, y * _vV.y);
		}

		Vector2 operator/(float _fValue)
		{
			return Vector2(x / _fValue, y / _fValue);
		}

		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}
	};
}