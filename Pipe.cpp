#include "Pipe.h"
#include <iostream>


Pipe::Pipe(sf::Vector2f size)
{
	m_PipeTexture = new sf::Texture();
	if (!m_PipeTexture->loadFromFile("pipe.png"))
	{
		std::cout << "Failed to load Pipe sprite" << std::endl;
	}
	else
	{
		sf::RectangleShape blockShape = sf::RectangleShape(size);
		blockShape.setTexture(m_PipeTexture);
		//blockShape.setOrigin(blockShape.getSize().x / 2, blockShape.getSize().y / 2);
		getPlatform() = blockShape;
	}
	getIsPipe() = true;
}