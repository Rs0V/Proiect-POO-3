
#include "Enemy.hpp"

Enemy::Enemy(const ID _id, const std::string _name, const IVec2 _pos)
	:
	Entity(_id, _name, _pos)
{
}

Enemy::~Enemy()
{
	std::cout << ">>> " << name << "(#" << id << ") destructed\n\n";
}

Enemy& Enemy::Move(const double delta_time, const Entity& player)
{
	int chance = rint(0, 100);
	if (chance > 50) {
		IVec2 move = (player.GetPos() - this->position).normalized() * stats.speed * delta_time;
		position += move;
	}
	return *this;
}
