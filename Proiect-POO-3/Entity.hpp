
#pragma once
#ifndef ENTITY
#define ENTITY

#include <string>

#include "Vec2.hpp"
#include "Stats.hpp"
#include "Id_Manager.hpp"

class Entity
{
protected:
	ID id;
	std::string name;

	IVec2 position;
	Stats stats;

	char sprite;

public:
	Entity(const ID _id, const std::string _name, const IVec2 _pos = IVec2());
	Entity(const Entity& other);
	virtual ~Entity() = 0;

	Entity& operator=(const Entity& other);

	bool operator==(const Entity& other) const;
	bool operator!=(const Entity& other) const;
	bool operator!() const;

	operator bool() const;
	operator char() const;

	friend std::ostream& operator<<(std::ostream& os, const Entity& entity)
	{
		os << entity.name << "(#" << entity.id << "): POS(" << entity.position << ")\n\n";
		return os;
	}

	IVec2 GetPos() const;
	Entity& Attack(Entity& other);
	Entity& TakeDamage(const int _dmg);
	bool Dodged() const;
	virtual Entity& Move(const double delta_time, const Entity& player) = 0;
};

inline Entity::~Entity() {}

#endif // !ENTITY
