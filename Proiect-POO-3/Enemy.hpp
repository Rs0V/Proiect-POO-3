
#pragma once
#ifndef ENEMY
#define ENEMY

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy(const ID _id, const std::string _name = "Enemy", const vec2 _pos = vec2());
	~Enemy() override;

	Enemy& Act(const double delta_time, const slist(Entity)& targets) override;

	friend class Enemy_Factory;
};



class Enemy_Factory
{
public:
	virtual ~Enemy_Factory() = 0;

	static Enemy grunt(const ID _id, const std::string _name = "Grunt", const vec2 _pos = vec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::grunt();
		enemy.sprite = 'o';
		enemy.attackRadius = 4;
		return enemy;
	};
	static Enemy elite(const ID _id, const std::string _name = "Elite", const vec2 _pos = vec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::elite();
		enemy.sprite = '*';
		enemy.attackRadius = 7;
		return enemy;
	};
	static Enemy hunter(const ID _id, const std::string _name = "Hunter", const vec2 _pos = vec2())
	{
		Enemy enemy(_id, _name, _pos);
		enemy.stats = Stats_Factory::hunter();
		enemy.sprite = 'V';
		enemy.attackRadius = 2;
		return enemy;
	};
};

inline Enemy_Factory::~Enemy_Factory() {}

#endif // !ENEMY
