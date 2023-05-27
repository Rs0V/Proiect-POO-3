
#pragma once
#ifndef VEC2
#define VEC2

#include <iostream>
#include "Macros.hpp"

template<typename T = double>
class Vec2
{
protected:
	T x, y;

public:
	T readonly x_ = x;
	T readonly y_ = y;

	Vec2(const T nr = 0);
	Vec2(const T _x, const T _y);
	Vec2(const Vec2<T>& other);
	Vec2(Vec2<T>&& other) noexcept;
	virtual ~Vec2();

	Vec2<T>& operator=(const Vec2<T>& other);
	Vec2<T>& operator=(Vec2<T>&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Vec2<T>& me)
	{
		is >> me.x >> me.y;
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const Vec2<T>& me)
	{
		os << "x: " << me.x << " | y: " << me.y;
		return os;
	}

	Vec2<T> operator+(const Vec2<T>& other) const;
	Vec2<T> operator-(const Vec2<T>& other) const;
	Vec2<T> operator*(const T factor) const;

	Vec2<T>& operator+=(const Vec2<T>& other);
	Vec2<T>& operator-=(const Vec2<T>& other);
	Vec2<T>& operator*=(const T factor);

	bool operator==(const Vec2<T>& other) const;
	bool operator!=(const Vec2<T>& other) const;
	bool operator!() const;

	bool operator>(const Vec2<T>& other) const;
	bool operator<(const Vec2<T>& other) const;
	bool operator<=(const Vec2<T>& other) const;
	bool operator>=(const Vec2<T>& other) const;

	operator bool() const;

	void set_x(const T _x);
	void set_y(const T _y);

	virtual double length() const;
	virtual void normalize();
	virtual Vec2<T> normalized() const;

	double dot_prod(const Vec2<T>& other);
};

typedef Vec2<int> IVec2;

#endif // !VEC2
