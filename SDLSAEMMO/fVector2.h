#pragma once
#include "fVector3.h"
#include <vector>
const float PI = 3.1415f;
const float degToRad = (PI / 180.f);
const float radToDeg = (180.f / PI);
class fVector2
{
public:
	fVector2();
	fVector2(float _x, float _y);
	fVector2(const fVector2& cpy);
	~fVector2();

	inline float Dot(const fVector2& p2) { return (this->x * p2.x) + (this->y * p2.y); }
	inline float Lenght() { return sqrtf((x*x) + (y*y)); }
	inline float SqrLenght() { return (x*x) + (y*y); }
	inline float angle() { return atan2f(y, x); }
	float Distance(fVector2& p2);
	float fCross(const fVector2& p2);
	float operator*=(const fVector2& rhs);
	fVector3 Cross(const fVector2& p2);
	fVector2 Sum(const fVector2& p2);
	fVector2 Mult(const float& p2);
	fVector2 Mult(const fVector2& p2);
	fVector2 Div(const fVector2& p2);
	fVector2 Div(const float& p2);
	fVector2 Projection(const fVector2& p2);
	inline fVector2 Squared() { return fVector2(this->x*this->x, this->y*this->y); }
	inline fVector2 lNormal() { return fVector2(-this->y, this->x); }
	inline fVector2 rNormal() { return fVector2(this->y, -this->x); }
	//Where x represents the min and y the max.
	inline bool Overlap(const fVector2& p2) 
	{ return (this->x < p2.y && this->x > p2.x) || (this->y < p2.y && this->y > p2.x); }
	inline float GetOverlapFactor(const fVector2& p2) 
	{ return (this->y < p2.y ? this->y : p2.y) - (this->x > p2.x ? this->x : p2.x); }
	fVector2 Unit();
	fVector2 Rotate(float ang, fVector2 center);
	fVector2 operator+=(const fVector2& rhs);
	fVector2 operator-=(fVector2& rhs);
	fVector2 operator*=(const float& rhs);
	fVector2 operator/=(const float& rhs);
	fVector2& operator=(const fVector2& rhs);
	fVector2& operator=(const struct b2Vec2& rhs);
	bool operator==(const fVector2& rhs);
	bool operator!=(const fVector2& rhs);
	struct b2Vec2 tobVec2();
	static std::vector<fVector2> Translate(std::vector<fVector2>& p, const fVector2& p2);
	static std::vector<fVector2> Rotate(std::vector<fVector2>& p, fVector2 center, float ang);
	static std::vector<fVector2> Scale(std::vector<fVector2>& p, float scale);
	
	static fVector2 zero;
	float x, y;
};

	fVector2 operator+(fVector2 lhs, const fVector2& rhs);
	fVector2 operator-(fVector2 lhs, fVector2 & rhs);
	fVector2 operator*(fVector2 lhs, const float& rhs);
	fVector2 operator/(fVector2 lhs, const float& rhs);
	float operator*(fVector2 lhs, fVector2& rhs);
