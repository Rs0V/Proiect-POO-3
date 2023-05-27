
#pragma once
#ifndef RENDERER
#define RENDERER

#include "Macros.hpp"
#include "World.hpp"
#include "Entity.hpp"

_system Renderer
{
	std::vector<std::vector<char>> buffer;
	static unique(Renderer) renderer;

	Renderer(const int screenWidth, const int screenHeight)
		:
		buffer(screenHeight, std::vector<char>(screenWidth, ' '))
	{}

public:
	Renderer(const Renderer& other) = delete;
	Renderer& operator=(const Renderer& other) = delete;

	static void Init(const int screenWidth, const int screenHeight);
	static unique(Renderer)& GetInst();

	void ClearBuffer();
	void Render(const std::vector<shared(Entity)>& entities);
};

#endif // !RENDERER
