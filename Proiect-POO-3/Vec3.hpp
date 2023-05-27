
#pragma once
#ifndef VEC3
#define VEC3

#include "Vec2.hpp"

template<typename T = double>
class Vec3 : public Vec2<T>
{
protected:
	T z;

public:
	T readonly z_ = z;

	Vec3(const T nr = 0);
	Vec3(const T _x, const T _y, const T _z);
	Vec3(const Vec2<T>& other, const T _z = 0);
	Vec3(const Vec3<T>& other);
	Vec3(Vec3<T>&& other) noexcept;
	~Vec3() override;

	Vec3<T>& operator=(const Vec3<T>& other);
	Vec3<T>& operator=(Vec3<T>&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Vec3<T>& me)
	{
		is >> me.x >> me.y >> me.z;
		return is;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& me)
	{
		os << "x: " << me.x << " | y: " << me.y << " | z: " << me.z;
		return os;
	}

	Vec3<T> operator+(const Vec3<T>& other) const;
	Vec3<T> operator-(const Vec3<T>& other) const;
	Vec3<T> operator*(const T factor) const;

	Vec3<T>& operator+=(const Vec3<T>& other);
	Vec3<T>& operator-=(const Vec3<T>& other);
	Vec3<T>& operator*=(const T factor);

	bool operator==(const Vec3<T>& other) const;
	bool operator!=(const Vec3<T>& other) const;
	bool operator!() const;

	bool operator>(const Vec3<T>& other) const;
	bool operator<(const Vec3<T>& other) const;
	bool operator<=(const Vec3<T>& other) const;
	bool operator>=(const Vec3<T>& other) const;

	operator bool() const;

	void set_x(const T _x);
	void set_y(const T _y);
	void set_z(const T _z);

	double length() const override;
	void normalize() override;
	Vec3<T> normalized() const override;
	double dot_prod(const Vec3<T>& other);
	Vec3<T> cross_prod(const Vec3<T>& other);
};

typedef Vec3<int> IVec3;

#endif // !VEC3
