
#include <conio.h>

#include "Player.hpp"
#include "Id_Manager.hpp"
#include <sstream>

Player::Player(const int64_t _id, const std::string _name, const IVec2 _pos, const int _inv_size)
	:
	Entity(_id, _name, _pos),
	inv_size(_inv_size),
	inventory(_inv_size)
{
	stats = Stats_Factory::player();
	sprite = '#';
}

Player::~Player()
{
	std::cout << ">>> " << name << "(#" << id << ") destructed\n\n";
}

Player& Player::Move(const double delta_time, const Entity& player)
{
	IVec2 move;
	switch (input)
	{
	case 'w':
		move = IVec2(0, -1);
		break;
	case 's':
		move = IVec2(0, 1);
		break;
	case 'a':
		move = IVec2(-1, 0);
		break;
	case 'd':
		move = IVec2(1, 0);
		break;
	}
	move *= delta_time * stats.speed;
	position += move;

	return *this;
}

Player& Player::IncreaseStat(const std::string stat_name, const int amount)
{
	if (stat_name == "speed") {
		stats.speed += amount;
	}
	else if (stat_name == "hp") {
		stats.hp += amount;
	}
	else if (stat_name == "damage" or stat_name == "dmg") {
		stats.dmg += amount;
	}
	else if (stat_name == "luck") {
		stats.luck += amount;
	}
	else if (stat_name == "inventory") {
		inv_size += amount;
	}
	return *this;
}

Player& Player::Input(const double delta_time, const std::vector<shared(Entity)>& entities)
{
	input = _getch();
	switch (input)
	{
	case 'w':
	case 's':
	case 'a':
	case 'd':
		Move(delta_time, *this);
		break;
	case ' ':
		for(int i = 0; i < entities.size(); ++i)
			Attack(*entities[i]);
		break;
	}
	return *this;
}