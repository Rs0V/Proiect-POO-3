
#include <conio.h>

#include "Player.hpp"
#include "Id_Manager.hpp"
#include <sstream>

Player::Player(const ID _id, const std::string _name, const vec2 _pos, const int _inv_size)
	:
	Entity(_id, _name, _pos),
	inv_size(_inv_size),
	inventory(_inv_size)
{
	stats = Stats_Factory::player();
	sprite = '#';
	attackRadius = 20;
}

Player::~Player()
{
}

Player& Player::Act(const double delta_time, const std::vector<shared(Entity)>& targets)
{
	if (stats.hp > 0)
	{
		char input = _getch();

		vec2 move;
		switch (input)
		{
		case 'w':
			move = vec2(0, -1);
			move *= delta_time * stats.speed;
			position += move;

			move = move.normalized() * 2;
			for (auto& target : targets)
				if (position == target->GetPos())
					position -= move;
			break;
		case 's':
			move = vec2(0, 1);
			move *= delta_time * stats.speed;
			position += move;

			move = move.normalized() * 2;
			for (auto& target : targets)
				if (position == target->GetPos())
					position -= move;
			break;
		case 'a':
			move = vec2(-1, 0);
			move *= delta_time * stats.speed;
			position += move;

			move = move.normalized() * 2;
			for (auto& target : targets)
				if (position == target->GetPos())
					position -= move;
			break;
		case 'd':
			move = vec2(1, 0);
			move *= delta_time * stats.speed;
			position += move;

			move = move.normalized() * 2;
			for (auto& target : targets)
				if (position == target->GetPos())
					position -= move;
			break;
		case ' ':
			for (auto& target : targets)
				if(target and *target)
					Attack(*target);
			break;
		}
	}
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
