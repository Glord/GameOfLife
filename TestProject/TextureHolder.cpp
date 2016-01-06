#include "TextureHolder.h"


TextureHolder::TextureHolder()
{
}


TextureHolder::~TextureHolder()
{
}

void TextureHolder::load(ID id, std::string file_name)
{
	sf::Texture texture;
	texture.loadFromFile(file_name);

	textures_map.push_back(std::make_pair(id, texture));
}

sf::Texture& TextureHolder::get(ID id)
{
	for (int i = 0; i < textures_map.size(); i++)
	{
		if (textures_map[i].first == id)
		{
			return textures_map[i].second;
		}
	}
	
}