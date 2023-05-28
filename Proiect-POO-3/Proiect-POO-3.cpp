
#include "Player.hpp"
#include "Enemy.hpp"
#include "Exception.hpp"
#include "Renderer.hpp"

int main()
{
	try {
		Renderer::GetInst(120, 30);

		shared(Player) player = smake(Player)(0, "Player", IVec2(90, 20));
		shared(Enemy) enemy = smake(Enemy)(Enemy_Factory::grunt(1, "Enemy", IVec2(60, 10)));

		std::vector<shared(Entity)> entities;
		std::vector<shared(Entity)> enemies;
		// PUSH ENTITIES
		entities.push_back(player);
		entities.push_back(enemy);
		// PUSH ENEMIES
		enemies.push_back(enemy);

		bool run = true;
		time_point t0 = time_now;
		time_point d0;
		time_point d1 = time_now;
		d0 = d1;
		while (run)
		{
			d1 = time_now;
			time_delta delta = d1 - d0;
			d0 = d1;

			if (player) {
				if (*player)
					player->Input(delta.count(), enemies);
				else
					player.reset();
			}
			for (auto& enemy : enemies)
				if (enemy) {
					if (*enemy and player) {
						enemy->Move(delta.count(), *player);
						enemy->Attack(*player);
					}
					else
						enemy.reset();
				}

			if (bool(*player) == false)
				run = false;

			Renderer::GetInst().Render(entities);
		}
		time_point t1 = time_now;
		time_delta delta = t1 - t0;
		std::cout << "\n>>> Game ran for " << delta.count() << "s\n\n";
	}
	catch (const my_exception& e) {
		std::cout << "Game ran into a problem:\n\t" << e.what() << "\n";
	}
	return 0;
}
