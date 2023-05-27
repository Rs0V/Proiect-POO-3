
#include "Renderer.hpp"
#include <iostream>

unique(Renderer) renderer = nullptr;

void Init(const int screenWidth, const int screenHeight)
{
	if (renderer == nullptr) {
		renderer = umake(Renderer)(screenWidth, screenHeight);
		return;
	}
	throw multiple_singletons_err("Renderer");
}

unique(Renderer)& GetInst()
{
	if (renderer) {
		return renderer;
	}
	throw uninitialized_singleton("Renderer");
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
		buffer[entity->GetPos().y_][entity->GetPos().x_] = *entity;
	}
	std::cout << buffer << std::flush;
}
