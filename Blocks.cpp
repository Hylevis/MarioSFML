#pragma once
#include "Blocks.h"
#include "Player.h"
#include <iostream>

Blocks::Blocks(bool isItemBlock, sf::Vector2f size)
{
	
	if (isItemBlock)
	{
		itemBlockTexture = new sf::Texture();
		if (!itemBlockTexture->loadFromFile("itemblock.jpg"))
		{
			std::cout << "Failed to load item block sprite" << std::endl;
		}
		else
		{
			sf::RectangleShape blockShape = sf::RectangleShape(size);
			blockShape.setTexture(itemBlockTexture);
			//blockShape.setOrigin(blockShape.getSize().x / 2, blockShape.getSize().y / 2);
			getPlatform() = blockShape;
			hasItem = true;
		}
	}
	else
	{

		itemBlockTexture = new sf::Texture();
		if (!itemBlockTexture->loadFromFile("brickblock.png"))
		{
			std::cout << "Failed to load item block sprite" << std::endl;
		}
		else
		{
			sf::RectangleShape blockShape = sf::RectangleShape(size);
			blockShape.setTexture(itemBlockTexture);
			//blockShape.setOrigin(blockShape.getSize().x / 2, blockShape.getSize().y / 2);
			getPlatform() = blockShape;
		}

	}
	getIsItemBlock() = isItemBlock;
	getIsBrickBlock() = true;
}

Blocks::~Blocks()
{
	delete itemBlockTexture;
	itemBlockTexture = nullptr;
}

