
#include "Player.hpp"
#include "Enemy.hpp"
#include "Exception.hpp"
#include "Renderer.hpp"

#include <conio.h>

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
				if (player and *player) {
					player->Act(0.3, enemies);
				}
				else
					player.reset();
			}
			for (auto& enemy : enemies) {
				if (enemy and *enemy) {
					enemy->Act(0.3, players);
				}
				else
					enemy.reset();
			}

			for (auto iter = players.begin(); iter != players.end(); ++iter) {
				if (*iter == nullptr) {
					players.erase(iter);
					if (players.empty())
						break;
					else
						iter = players.begin();
				}
			}
			for (auto iter = enemies.begin(); iter != enemies.end(); ++iter) {
				if (*iter == nullptr) {
					enemies.erase(iter);
					if (enemies.empty())
						break;
					else
						iter = enemies.begin();
				}
			}

			if (players.empty() or enemies.empty())
				run = false;

			Renderer::GetInst().Render(entities);
		}
		time_point t1 = time_now;
		time_delta delta = t1 - t0;
		std::cout << "\n>>> Game ran for " << delta.count() << "s\n\n";

		std::cout << "\n>>> Press ESC to exit\n\n";

		char quit = _getch();
		while (quit != 27) {
			quit = _getch();
		}
	}
	catch (const my_exception& e) {
		std::cout << "Game ran into a problem:\n\t" << e.what() << "\n";

		std::cout << "\n>>> Press ESC to exit\n\n";

		char quit = _getch();
		while (quit != 27) {
			quit = _getch();
		}
	}
	return 0;
}
