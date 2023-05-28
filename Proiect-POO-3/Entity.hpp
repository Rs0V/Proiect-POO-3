
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

	vec2 position;
	Stats stats;

	char sprite;
	double attackRadius;

	bool Dodged() const;
	void TakeDamage(const int _dmg);
	void Attack(Entity& other);

public:
	Entity(const ID _id, const std::string _name, const vec2 _pos = vec2());
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

	vec2 GetPos() const;
	virtual Entity& Act(const double delta_time, const slist(Entity)& targets) = 0;
};

inline Entity::~Entity() {}

#endif // !ENTITY
