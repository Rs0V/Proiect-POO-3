
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

	friend std::ostream& operator<<(std::ostream& os, const Vec3<T>& me)
	{
		os << "x: " << me.x << " | y: " << me.y << " | z: " << me.z;
		return os;
	}

	Vec3<T> operator+(const Vec3<T>& other) const;
	Vec3<T> operator-(const Vec3<T>& other) const;
	template<typename U>
	Vec3<T> operator*(const U factor) const
	{
		return Vec3<T>(this->x * factor, this->y * factor, this->z * factor);
	}

	Vec3<T>& operator+=(const Vec3<T>& other);
	Vec3<T>& operator-=(const Vec3<T>& other);
	template<typename U>
	Vec3<T>& operator*=(const U factor)
	{
		this->x *= factor;
		this->y *= factor;
		this->z *= factor;

		return *this;
	}

	bool operator==(const Vec3<T>& other) const;
	bool operator!=(const Vec3<T>& other) const;
	bool operator!() const;
	operator bool() const;

	bool operator>(const Vec3<T>& other) const;
	bool operator<(const Vec3<T>& other) const;
	bool operator<=(const Vec3<T>& other) const;
	bool operator>=(const Vec3<T>& other) const;

	void set_z(const T _z);

	double length() const override;
	double length2() const override;
	Vec3<T>& normalize() override;
	Vec3<T> normalized() const override;
	double dot_prod(const Vec3<T>& other);
	Vec3<T> cross_prod(const Vec3<T>& other);
};

typedef Vec3<> vec3;
typedef Vec3<int> ivec3;

#endif // !VEC3



//////////////////////////////////////////////////////////////////////////////////////////



template<typename T>
Vec3<T>::Vec3(const T nr)
	:
	Vec2<T>::Vec2(nr),
	z(nr)
{
}

template<typename T>
Vec3<T>::Vec3(const T _x, const T _y, const T _z)
	:
	Vec2<T>::Vec2(_x, _y),
	z(_z)
{
}

template<typename T>
Vec3<T>::Vec3(const Vec2<T>& other, const T _z)
	:
	Vec2<T>::Vec2(other),
	z(_z)
{
}

template<typename T>
Vec3<T>::Vec3(const Vec3<T>& other)
	:
	Vec2<T>::Vec2(other.x, other.y),
	z(other.z)
{
}

template<typename T>
Vec3<T>::Vec3(Vec3<T>&& other) noexcept
	:
	Vec2<T>::Vec2(0, 0),
	z(0)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	other.x = 0;
	other.y = 0;
	other.z = 0;
}

template<typename T>
Vec3<T>::~Vec3()
{
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(const Vec3<T>& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(Vec3<T>&& other) noexcept
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	other.x = 0;
	other.y = 0;
	other.z = 0;

	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const
{
	return Vec3<T>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const
{
	return Vec3<T>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

template<typename T>
bool Vec3<T>::operator==(const Vec3<T>& other) const
{
	return (!cross_prod(*this, other) and length() == other.length());
}

template<typename T>
bool Vec3<T>::operator!=(const Vec3<T>& other) const
{
	return !(*this == other);
}

template<typename T>
bool Vec3<T>::operator!() const
{
	return !(this->x and this->y and this->z);
}

template<typename T>
Vec3<T>::operator bool() const
{
	return (this->x != 0 and this->y != 0 and this->z != 0);
}

template<typename T>
bool Vec3<T>::operator>(const Vec3<T>& other) const
{
	return (length() > other.length());
}

template<typename T>
bool Vec3<T>::operator<(const Vec3<T>& other) const
{
	return (length() < other.length());
}

template<typename T>
bool Vec3<T>::operator<=(const Vec3<T>& other) const
{
	return !(length() > other.length());
}

template<typename T>
bool Vec3<T>::operator>=(const Vec3<T>& other) const
{
	return !(length() < other.length());
}

template<typename T>
void Vec3<T>::set_z(const T _z)
{
	this->z = _z;
}

template<typename T>
double Vec3<T>::length() const
{
	return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template<typename T>
double Vec3<T>::length2() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

template<typename T>
Vec3<T>& Vec3<T>::normalize()
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	this->x /= len;
	this->y /= len;
	this->z /= len;

	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::normalized() const
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	return Vec3<T>(this->x / len, this->y / len, this->z / len);
}

template<typename T>
double Vec3<T>::dot_prod(const Vec3<T>& other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

template<typename T>
Vec3<T> Vec3<T>::cross_prod(const Vec3<T>& other)
{
	return Vec3<T>(this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x);
}
