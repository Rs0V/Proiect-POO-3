
#pragma once
#ifndef RENDERER
#define RENDERER

#include "Macros.hpp"
#include "Entity.hpp"

class Renderer
{
	matrix(char) buffer;
	static Renderer* renderer;

	Renderer(const int screenWidth, const int screenHeight)
		:
		buffer(screenHeight, std::vector<char>(screenWidth, ' '))
	{}

public:
	/*~Renderer() {
		if (renderer != nullptr)
			delete renderer;
	}*/

	Renderer(const Renderer& other) = delete;
	Renderer& operator=(const Renderer& other) = delete;

	static Renderer& GetInst(const int screenWidth = 0, const int screenHeight = 0);

	void ClearBuffer();
	void Render(const std::vector<shared(Entity)>& entities);
};

#endif // !RENDERER
