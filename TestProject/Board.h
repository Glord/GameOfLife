#pragma once
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;



class Board
{
private:
	Grid grid1;
	Grid grid2;

	std::vector<int> staying_alive_rules;
	std::vector<int> become_alive_rules;

	RectangleShape cell_rect;

public:
	Board();
	~Board();

	void setGrids(int size);
	void showCurrGrid();
	void swapGrids();
	void calculateGeneration();

	void rendering(RenderWindow *window);

	Grid *curr_grid;
	Grid *old_grid;

	int grid_size;

	float CELL_SPACE;
	float SIM_OFFSET_X;
	float SIM_OFFSET_Y;
	float CELL_SIZE;

};

