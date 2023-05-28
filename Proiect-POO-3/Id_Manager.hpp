
#pragma once
#ifndef ID_MANAGER
#define ID_MANAGER

#include <vector>
#include <algorithm>

#include "Exception.hpp"
#include "Macros.hpp"

class Id_Manager
{
	static std::vector<int64_t> used_ids;

public:
	virtual ~Id_Manager() = 0;

	static void Mark_Id(const ID id);
};

inline Id_Manager::~Id_Manager() = default;

#endif // !ID_MANAGER
