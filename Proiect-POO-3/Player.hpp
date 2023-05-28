
#pragma once
#ifndef PLAYER
#define PLAYER

#include <vector>

#include "Entity.hpp"

class Player : public Entity
{
	std::vector<std::string> inventory;
	int inv_size;

	char input;

	Player& Move(const double delta_time, const Entity& player) override;

public:
	Player(const ID _id, const std::string _name = "Player", const IVec2 _pos = IVec2(), const int _inv_size = 8);
	Player(const Player& other) = delete;
	~Player() override;

	Player& operator=(const Player& other) = delete;

	Player& IncreaseStat(const std::string stat_name, const int amount);
	Player& Input(const double delta_time, const std::vector<shared(Entity)>& others);
};

#endif // !PLAYER
