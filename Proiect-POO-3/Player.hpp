
#pragma once
#ifndef PLAYER
#define PLAYER

#include <vector>

#include "Entity.hpp"

class Player : public Entity
{
	std::vector<std::string> inventory;
	int inv_size;

public:
	Player(const ID _id, const std::string _name = "Player", const vec2 _pos = vec2(), const int _inv_size = 8);
	Player(const Player& other) = delete;
	~Player() override;

	Player& operator=(const Player& other) = delete;

	Player& IncreaseStat(const std::string stat_name, const int amount);
	Player& Act(const double delta_time, const std::vector<shared(Entity)>& targets) override;
};

#endif // !PLAYER
