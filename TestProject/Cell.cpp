#include "Cell.h"


Cell::Cell()
{
	is_alive = false;
}


Cell::~Cell()
{
}

bool Cell::isAlive()
{
	return is_alive;
}

void Cell::setAlive()
{
	is_alive = true;
}

void Cell::setDead()
{
	is_alive = false;
}