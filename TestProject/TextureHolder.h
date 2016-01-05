#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
class TextureHolder
{
public:
	TextureHolder();
	~TextureHolder();

	enum ID{slow_down_button, speed_up_button, grid_bg, pause_button, 
			start_button, one_step_button, clear_button};

	void load(ID id, std::string file_name);
	sf::Texture& get(ID id);

	std::vector<std::pair<ID, sf::Texture>> textures_map;
};

