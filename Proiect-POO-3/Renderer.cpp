
#include "Renderer.hpp"
#include <iostream>
#include "Exception.hpp"
#include <stdlib.h>

Renderer* Renderer::renderer = nullptr;

Renderer& Renderer::GetInst(const int screenWidth, const int screenHeight)
{
	if (renderer == nullptr) {
		renderer = new Renderer(screenWidth, screenHeight);
	}
	return *renderer;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	for (T elem : v) {
		os << elem;
	}
	return os;
}

void Renderer::ClearBuffer()
{
	for (int i = 0; i < buffer.size(); ++i) {
		for (int j = 0; j < buffer[i].size(); ++j)
			buffer[i][j] = ' ';
	}
}

void Renderer::Render(const std::vector<shared(Entity)>& entities)
{
	ClearBuffer();
	for (auto& entity : entities) {
		if (entity and *entity) {
			if (entity->GetPos().x_ < 0 or entity->GetPos().y_ < 0
				or entity->GetPos().x_ > buffer[0].size() - 1
				or entity->GetPos().y_ > buffer.size() - 1)
			{
				std::ostringstream oss;
				oss << *entity;
				throw out_of_bounds(oss.str());
			}
			buffer[int(entity->GetPos().y_)][int(entity->GetPos().x_)] = *entity;
		}
	}
	std::system("cls");
	std::cout << buffer << std::flush;
}
