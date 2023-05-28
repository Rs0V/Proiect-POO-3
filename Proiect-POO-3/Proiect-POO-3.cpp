
#include "Player.hpp"
#include "Enemy.hpp"
#include "Exception.hpp"
#include "Renderer.hpp"

int main()
{
	try {
		Renderer::GetInst(120, 30);

		std::vector<shared(Entity)> players;
		std::vector<shared(Entity)> enemies;
		std::vector<shared(Entity)> entities;

		players.push_back(smake(Player)(0, "Gion", vec2(60, 20)));

		enemies.push_back(smake(Enemy)(Enemy_Factory::elite(1, "Vali", vec2(30, 10))));

		for (auto& player : players) {
			entities.push_back(player);
		}
		for (auto& enemy : enemies) {
			entities.push_back(enemy);
		}



		bool run = true;
		time_point t0 = time_now;
		while (run)
		{
			for (auto& player : players) {
				if (*player) {
					player->Act(0.3, enemies);
				}
			}
			for (auto& enemy : enemies) {
				if (*enemy) {
					enemy->Act(0.3, players);
				}
			}
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
