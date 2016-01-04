#pragma once
#include "Cell.h"
#include <random>
#include <time.h>
#include <vector>

using namespace std;

class Grid
{
public:
	Grid();
	~Grid();

	Cell getCellAt(int x, int y);
	void setCellAsAliveAt(int x, int y);
	void setCellAsDeadAt(int x, int y);
	void setCellAt(int x, int y, bool state);
	void clearGrid();
	void fillGrid(int size);
	int countNeighboursAt(int x, int y);

	void addShape();


private:
	vector<vector<Cell>> grid;

};

