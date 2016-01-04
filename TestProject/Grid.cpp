#include "Grid.h"

Grid::Grid()
{
}


Grid::~Grid()
{
}

Cell Grid::getCellAt(int x, int y)
{
	return grid[x][y];
}

void Grid::setCellAsAliveAt(int x, int y)
{
	grid[x][y].setAlive();
}

void Grid::setCellAsDeadAt(int x, int y)
{
	grid[x][y].setDead();
}

void Grid::setCellAt(int x, int y, bool state)
{
	if (state == true)
		grid[x][y].setAlive();
	else
		grid[x][y].setDead();
}

void Grid::clearGrid()
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			grid[i][j].setDead();
		}
	}
}

void Grid::fillGrid(int size)
{
	Cell c;
	vector<Cell> tmp_grid;
	
	for (int i = 0; i < size; i++)
		tmp_grid.push_back(c);

	for (int j = 0; j < size; j++)
		grid.push_back(tmp_grid);

}

int Grid::countNeighboursAt(int x, int y)
{
	return (int)grid[x - 1][y - 1].isAlive() +
		(int)grid[x][y - 1].isAlive() +
		(int)grid[x + 1][y - 1].isAlive() +
		(int)grid[x - 1][y].isAlive() +
		(int)grid[x + 1][y].isAlive() +
		(int)grid[x - 1][y + 1].isAlive() +
		(int)grid[x][y + 1].isAlive() +
		(int)grid[x + 1][y + 1].isAlive();
}

void Grid::addShape()
{

}