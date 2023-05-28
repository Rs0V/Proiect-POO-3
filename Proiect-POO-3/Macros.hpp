
#pragma once
#ifndef MACROS
#define MACROS

#include <memory>
#include <random>
#include <chrono>
#include <vector>

#define readonly const&

#define unique(type) std::unique_ptr<type>
#define umake(type) std::make_unique<type>

#define shared(type) std::shared_ptr<type>
#define smake(type) std::make_shared<type>

#define ulist(type) std::vector<unique(type)>
#define slist(type) std::vector<shared(type)>

extern std::random_device rd;
extern std::mt19937 rng;

#define rint(min, max) std::uniform_int_distribution<int>(min, max)(rng)
#define rdouble(min, max) std::uniform_real_distribution<double>(min, max)(rng)

#define time_point std::chrono::time_point<std::chrono::system_clock>
#define time_now std::chrono::system_clock::now()
#define time_delta std::chrono::duration<double>

template <typename T>
T lerp(T min, T max, double amount)
{
	return T(min + (max - min) * amount);
}

typedef int64_t ID;

#endif // !MACROS
