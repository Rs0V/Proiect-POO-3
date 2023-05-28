
#pragma once
#ifndef ID_MANAGER
#define ID_MANAGER

#include <vector>
#include <algorithm>

#include "Exception.hpp"
#include "Macros.hpp"

class Id_Manager
{
	std::vector<ID> used_ids;
	static Id_Manager* id_manager;

	Id_Manager() = default;
	
public:
	/*~Id_Manager() {
		if (id_manager != nullptr)
			delete id_manager;
	}*/

	Id_Manager(const Id_Manager& other) = delete;
	Id_Manager& operator=(const Id_Manager& other) = delete;

	static Id_Manager& GetInst();

	void Mark_Id(const ID id);
};

#endif // !ID_MANAGER
