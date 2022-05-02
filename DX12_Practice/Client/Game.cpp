#include "pch.h"
#include "Game.h"
#include "Engine.h"


#pragma comment(lib, "Engine.lib")

void Game::Init(const WindowInfo& info)
{
	GEngine->Init(info);
}

void Game::Update()
{
}