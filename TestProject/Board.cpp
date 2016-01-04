#include "Board.h"




Board::Board()
{
	CELL_SPACE = 1.0f;
	CELL_SIZE = 10.0f;
	SIM_OFFSET_X = 200.0f;
	SIM_OFFSET_Y = 100.0f;

	//conway's game of life rules
	staying_alive_rules.push_back(2);
	staying_alive_rules.push_back(3);
	become_alive_rules.push_back(3);

	curr_grid = &grid1;
	old_grid = &grid2;
	cell_rect.setFillColor(Color::Red);
	cell_rect.setSize(Vector2f(CELL_SIZE, CELL_SIZE));
	
}

Board::~Board()
{
}

void Board::setGrids(int size)
{
	grid_size = size;
	curr_grid->fillGrid(size);
	old_grid->fillGrid(size);
}

void Board::showCurrGrid()
{
	//system("cls");
	for (int i = 0; i < grid_size; i++)
	{
		for (int j = 0; j < grid_size; j++)
		{
			std::cout << curr_grid->getCellAt(i, j).isAlive();
		}
		std::cout << endl;
	}
	std::cout << "----------" << endl;
}

void Board::swapGrids()
{
	Grid *tmp = old_grid;
	old_grid = curr_grid;
	curr_grid = tmp;
}

void Board::calculateGeneration()
{
	int alive_neighbours = 0;
	for (int i = 1; i < grid_size - 1; i++)
	{
		for (int j = 1; j < grid_size - 1; j++)
		{

			alive_neighbours = old_grid->countNeighboursAt(i, j);

			if (old_grid->getCellAt(i, j).isAlive() == false)
			{
				for (int x = 0; x < become_alive_rules.size(); x++)
				{
					if (alive_neighbours == become_alive_rules[x])
					{
						curr_grid->setCellAsAliveAt(i, j);
						break;
					}
				}
			}

			if (old_grid->getCellAt(i, j).isAlive() == true)
			{
				for (int x = 0; x < staying_alive_rules.size(); x++)
				{
					if (alive_neighbours == staying_alive_rules[x])
					{
						curr_grid->setCellAsAliveAt(i, j);
						break;
					}
				}
			}
		}
	}
}

void Board::rendering(RenderWindow *window)
{

	for (int i = 0; i < grid_size; i++)
	{
		for (int j = 0; j < grid_size; j++)
		{
			if (curr_grid->getCellAt(i, j).isAlive() == true)
			{
				cell_rect.setPosition(Vector2f(SIM_OFFSET_X + i*CELL_SIZE + (i - 1)*CELL_SPACE, SIM_OFFSET_Y + j*CELL_SIZE + (j - 1)*CELL_SPACE));
				window->draw(cell_rect);
			}
		}
	}
}