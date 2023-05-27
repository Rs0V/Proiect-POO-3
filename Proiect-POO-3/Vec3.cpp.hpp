
#include "Vec3.hpp"
#include "Exception.hpp"

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
	x = other.x;
	y = other.y;
	z = other.z;

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
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(Vec3<T>&& other) noexcept
{
	x = other.x;
	y = other.y;
	z = other.z;

	other.x = 0;
	other.y = 0;
	other.z = 0;

	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T>& other) const
{
	return Vec3<T>(x + other.x, y + other.y, z + other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T>& other) const
{
	return Vec3<T>(x - other.x, y - other.y, z - other.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T factor) const
{
	return Vec3<T>(x * factor, y * factor, z * factor);
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;

	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(const T factor)
{
	x *= factor;
	y *= factor;
	z *= factor;

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
	return !(x and y and z);
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
	return (length() <= other.length());
}

template<typename T>
bool Vec3<T>::operator>=(const Vec3<T>& other) const
{
	return (length() >= other.length());
}

template<typename T>
Vec3<T>::operator bool() const
{
	return (x != 0 and y != 0 and z != 0);
}

template<typename T>
void Vec3<T>::set_x(const T _x)
{
	x = _x;
}

template<typename T>
void Vec3<T>::set_y(const T _y)
{
	y = _y;
}

template<typename T>
void Vec3<T>::set_z(const T _z)
{
	z = _z;
}

template<typename T>
double Vec3<T>::length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
void Vec3<T>::normalize()
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	x /= len;
	y /= len;
	z /= len;
}

template<typename T>
Vec3<T> Vec3<T>::normalized() const
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	return Vec3<T>(x / len, y / len, z / len);
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
