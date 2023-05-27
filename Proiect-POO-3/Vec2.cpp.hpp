
#include "Vec2.hpp"

#include "Exception.hpp"

template<typename T>
Vec2<T>::Vec2(const T nr)
	:
	x(nr),
	y(nr)
{
}

template<typename T>
Vec2<T>::Vec2(const T _x, const T _y)
	:
	x(_x),
	y(_y)
{
}

template<typename T>
Vec2<T>::Vec2(const Vec2<T>& other)
	:
	x(other.x),
	y(other.y)
{
}

template<typename T>
Vec2<T>::Vec2(Vec2<T>&& other) noexcept
	:
	x(0),
	y(0)
{
	x = other.x;
	y = other.y;

	other.x = 0;
	other.y = 0;
}

template<typename T>
Vec2<T>::~Vec2()
{
}

template<typename T>
Vec2<T>& Vec2<T>::operator=(const Vec2<T>& other)
{
	x = other.x;
	y = other.y;

	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator=(Vec2<T>&& other) noexcept
{
	x = other.x;
	y = other.y;

	other.x = 0;
	other.y = 0;

	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T>& other) const
{
	return Vec2<T>(x + other.x, y + other.y);
}

template<typename T>
Vec2<T> Vec2<T>::operator-(const Vec2<T>& other) const
{
	return Vec2<T>(x - other.x, y - other.y);
}

template<typename T>
Vec2<T> Vec2<T>::operator*(const T factor) const
{
	return Vec2<T>(x * factor, y * factor);
}

template<typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator*=(const T factor)
{
	x *= factor;
	y *= factor;

	return *this;
}

template<typename T>
bool Vec2<T>::operator==(const Vec2<T>& other) const
{
	return (!(y - other.y) and !(x * other.y - y * other.x) and !(other.x - x) and length() == other.length());
}

template<typename T>
bool Vec2<T>::operator!=(const Vec2<T>& other) const
{
	return !(*this == other);
}

template<typename T>
bool Vec2<T>::operator!() const
{
	return !(x and y);
}

template<typename T>
bool Vec2<T>::operator>(const Vec2<T>& other) const
{
	return (length() > other.length());
}

template<typename T>
bool Vec2<T>::operator<(const Vec2<T>& other) const
{
	return (length() < other.length());
}

template<typename T>
bool Vec2<T>::operator<=(const Vec2<T>& other) const
{
	return (length() <= other.length());
}

template<typename T>
bool Vec2<T>::operator>=(const Vec2<T>& other) const
{
	return (length() >= other.length());
}

template<typename T>
Vec2<T>::operator bool() const
{
	return (x != 0 and y != 0);
}

template<typename T>
void Vec2<T>::set_x(const T _x)
{
	x = _x;
}

template<typename T>
void Vec2<T>::set_y(const T _y)
{
	y = _y;
}

template<typename T>
double Vec2<T>::length() const
{
	return std::sqrt(x * x + y * y);
}

template<typename T>
void Vec2<T>::normalize()
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	x /= len;
	y /= len;
}

template<typename T>
Vec2<T> Vec2<T>::normalized() const
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	return Vec2<T>(x / len, y / len);
}

template<typename T>
double Vec2<T>::dot_prod(const Vec2<T>& other)
{
	return this->x * other.x + this->y * other.y;
}
