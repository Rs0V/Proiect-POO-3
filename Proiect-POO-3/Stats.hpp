
#pragma once
#ifndef STATS
#define STATS

struct Stats
{
	int speed;
	int hp;
	int dmg;
	int luck;

	Stats(const int _speed = 1,
		const int _hp = 100,
		const int _dmg = 1,
		const int _luck = 1)
		:
		speed(_speed),
		hp(_hp),
		dmg(_dmg),
		luck(_luck)
	{
	}
	Stats(const Stats& other)
		:
		speed(other.speed),
		hp(other.hp),
		dmg(other.dmg),
		luck(other.luck)
	{
	}
	Stats& operator=(const Stats& other)
	{
		speed = other.speed;
		hp = other.hp;
		dmg = other.dmg;
		luck = other.luck;

		return *this;
	}
};

class Stats_Factory
{
public:
	virtual ~Stats_Factory() = 0;

	static Stats player() { return Stats(10, 100, 10, 3); };
	static Stats grunt() { return Stats(4, 50, 2, 1); };
	static Stats elite() { return Stats(6, 100, 5, 1); };
	static Stats hunter() { return Stats(2, 200, 12, 1); };
};

inline Stats_Factory::~Stats_Factory() {}

#endif // !STATS
