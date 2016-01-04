#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"

using namespace sf;

class Game
{

public:
	Game();
	void run();

	Board board;
	bool game_paused;

private:
	void processEvents();
	void update(Time deltaTime);
	void render();
	void handlePlayerInput(Keyboard::Key key, bool isPressed);

private:
	RenderWindow mWindow;
	Time TimePerFrame;
	float time_divider;
	RectangleShape rect;

	unsigned int generations_amount;
	
};

