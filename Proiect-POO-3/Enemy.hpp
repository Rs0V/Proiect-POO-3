
#pragma once
#ifndef ENEMY
#define ENEMY

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy(const ID _id, const std::string _name = "Enemy", const IVec2 _pos = IVec2());
	~Enemy() override;

	Enemy& Move(const double delta_time, const Entity& player) override;

	friend class Enemy_Factory;
};

class Enemy_Factory
{
public:
	virtual ~Enemy_Factory() = 0;

	static Enemy grunt(const ID _id, const std::string _name = "Enemy", const IVec2 _pos = IVec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::grunt();
		enemy.sprite = 'o';
		return enemy;
	};
	static Enemy elite(const ID _id, const std::string _name = "Enemy", const IVec2 _pos = IVec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::elite();
		enemy.sprite = '*';
		return enemy;
	};
	static Enemy hunter(const ID _id, const std::string _name = "Enemy", const IVec2 _pos = IVec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::hunter();
		enemy.sprite = 'V';
		return enemy;
	};
};

inline Enemy_Factory::~Enemy_Factory() {}

#endif // !ENEMY
