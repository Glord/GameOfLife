#pragma once
#include <SFML\Graphics.hpp>

class Cell
{
public:
	Cell();
	~Cell();

	bool isAlive();
	void setAlive();
	void setDead();

private:
	bool is_alive;
};

