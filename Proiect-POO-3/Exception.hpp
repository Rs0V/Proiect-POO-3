
#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>
#include <sstream>

class my_exception : public std::exception
{
public:
	const char* what() const noexcept override {
		return "Just my exception";
	}
};

class out_of_bounds : public my_exception
{
	std::string info;

public:
	out_of_bounds(const std::string& _info)
		:
		info(_info)
	{
		std::ostringstream oss;
		oss << "Entity out of bounds!  :  " << info;
		info = oss.str();
	}
	const char* what() const noexcept override {
		return info.c_str();
	}
};

class negative_dimensions : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Dimensions of an object/world can't be negative!";
	}
};

class division_by_zero : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Encountered division by zero!";
	}
};

class normalize_by_zero : public division_by_zero
{
public:
	const char* what() const noexcept override {
		return "Encountered division by zero while normalizing vector!";
	}
};

class repeating_id_err : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Entity ID is not unique!";
	}
};

class multiple_singletons_err : public my_exception
{
	std::string info;

public:
	multiple_singletons_err(const std::string& _info)
		:
		info(_info)
	{
		std::ostringstream oss;
		oss << "Multiple instances of the " << info << " singleton are being created!";
		info = oss.str();
	}
	const char* what() const noexcept override {
		return info.c_str();
	}
};

class uninitialized_singleton : public my_exception
{
	std::string info;

public:
	uninitialized_singleton(const std::string& _info)
		:
		info(_info)
	{
		std::ostringstream oss;
		oss << info << " singleton not initialized before use!";
		info = oss.str();
	}
	const char* what() const noexcept override {
		return info.c_str();
	}
};

#endif // !EXCEPTION
