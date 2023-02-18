#include "Staircase.h"
#include <iostream>


Staircase::Staircase(sf::Vector2f size)
{
	stairBlockTexture = new sf::Texture();
	if (!stairBlockTexture->loadFromFile("stairblock.png"))
	{
		std::cout << "Failed to load item block sprite" << std::endl;
	}
	else
	{
		sf::RectangleShape blockShape = sf::RectangleShape(size);
		blockShape.setTexture(stairBlockTexture);
		getPlatform() = blockShape;
	}
}