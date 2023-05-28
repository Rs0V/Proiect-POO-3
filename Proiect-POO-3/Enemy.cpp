
#include "Enemy.hpp"

Enemy::Enemy(const ID _id, const std::string _name, const vec2 _pos)
	:
	Entity(_id, _name, _pos)
{
}

Enemy::~Enemy()
{
}

Enemy& Enemy::Act(const double delta_time, const slist(Entity)& targets)
{
	int chance = rint(0, 100);
	if (chance > 10) {
		int pick = rint(0, targets.size() - 1);
		vec2 move = (targets[pick]->GetPos() - position).normalized() * stats.speed * delta_time;
		position += move;
		Attack(*targets[pick]);
	}
	return *this;
}
