
#include "Entity.hpp"

Entity::Entity(const ID _id, const std::string _name, const IVec2 _pos)
	:
	name(_name),
	position(_pos)
{
	Id_Manager::Mark_Id(_id);
	id = _id;
}

Entity::Entity(const Entity& other)
	:
	name(other.name),
	position(other.position),
	id(other.id),
	stats(other.stats),
	sprite(other.sprite)
{
}

Entity& Entity::operator=(const Entity& other)
{
	name = other.name;
	position = other.position;
	id = other.id;
	stats = other.stats;
	sprite = other.sprite;

	return *this;
}

bool Entity::operator==(const Entity& other) const {
	return (id == other.id);
}

bool Entity::operator!=(const Entity& other) const {
	return (id != other.id);
}

bool Entity::operator!() const {
	return (stats.hp <= 0);
}

Entity::operator bool() const {
	return (stats.hp > 0);
}

Entity::operator char() const
{
	return sprite;
}

IVec2 Entity::GetPos() const {
	return position;
}

Entity& Entity::Attack(Entity& other) {
	if ((position - other.GetPos()).length() < 3) {
		other.TakeDamage(stats.dmg);
	}
	return *this;
}

Entity& Entity::TakeDamage(const int _dmg)
{
	if (stats.hp > 0 and Dodged() == false)
	{
		int dmgTaken = rint(_dmg - int(_dmg * 0.5), _dmg + int(_dmg * 0.5));
		stats.hp -= dmgTaken;
	}
	return *this;
}

bool Entity::Dodged() const
{
	// Min luck -> 1      Max luck -> 8
	int chance = lerp<int>(20, 50, double(stats.luck - 1) * 0.125);
	int roulette = rint(0, 100);
	if (roulette <= chance) {
		return true;
	}
	return false;
}
