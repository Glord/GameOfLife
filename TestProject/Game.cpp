#include "Game.h"


Game::Game() : mWindow(VideoMode(1280, 1024), "SFML App")
{
	time_divider = 10.0f;
	TimePerFrame = seconds(1.0f / time_divider);
	game_paused = true;

	generations_amount = 0;
	
}

void Game::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	board.setGrids(80);

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case Event::KeyReleased:
			//handlePlayerInput(event.key.code, false);
			break;
		case Event::Closed:
			mWindow.close();
			break;
		case Event::MouseWheelMoved:
			if (event.mouseWheel.delta > 0) mWindow.close();
			break;
		}
		if (game_paused)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(mWindow);
				int x = (position.x - board.SIM_OFFSET_X - board.CELL_SIZE) / (board.CELL_SIZE + board.CELL_SPACE);
				int y = (position.y - board.SIM_OFFSET_Y - board.CELL_SIZE) / (board.CELL_SIZE + board.CELL_SPACE);
				if (x + 1 > 0 && x + 1 < board.grid_size &&
					y + 1 > 0 && y + 1 < board.grid_size)
					board.curr_grid->setCellAsAliveAt(x + 1, y + 1);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i position = sf::Mouse::getPosition(mWindow);
				int x = (position.x - board.SIM_OFFSET_X - board.CELL_SIZE) / (board.CELL_SIZE + board.CELL_SPACE);
				int y = (position.y - board.SIM_OFFSET_Y - board.CELL_SIZE) / (board.CELL_SIZE + board.CELL_SPACE);
				if (x + 1 > 0 && x + 1 < board.grid_size &&
					y + 1 > 0 && y + 1 < board.grid_size)
					board.curr_grid->setCellAsDeadAt(x + 1, y + 1);
			}
		}
	}
}

void Game::update(Time deltaTime)
{
	if (!game_paused)
	{
		board.old_grid->clearGrid();
		board.swapGrids();
		board.calculateGeneration();
		//generations_amount++;
	}
}

void Game::render()
{
	mWindow.clear(sf::Color(50, 50, 50, 255));
	board.rendering(&mWindow);
	mWindow.display();
}

void Game::handlePlayerInput(Keyboard::Key key, bool isPressed)
{

	if (key == Keyboard::D)
	{
		if (time_divider < 60.0f)
		{
			time_divider += 2.0f;
			TimePerFrame = seconds(1.0f / time_divider);
		}
	}

	if (key == Keyboard::A)
	{
		if (time_divider > 2.0f)
		{
			time_divider -= 2.0f;
			TimePerFrame = seconds(1.0f / time_divider);
		}
	}

	if (key == Keyboard::C)
	{
		board.curr_grid->clearGrid();
		board.old_grid->clearGrid();
		game_paused = true;
	}

	if (key == Keyboard::Space)
	{
		if (game_paused == true)
			game_paused = false;
		else
			game_paused = true;
	}

	if (key == Keyboard::W)
	{
		if (game_paused == true)
		{
			board.old_grid->clearGrid();
			board.swapGrids();
			board.calculateGeneration();
		}
	}
}