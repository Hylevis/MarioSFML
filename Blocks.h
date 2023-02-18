#pragma once
#include "Drawable.h"
#include "Platforms.h"

class Blocks : public Platforms
{
public:
	Blocks(bool isItemBlock,sf::Vector2f size);
	~Blocks();
	bool& getHasItem() { return hasItem; };

	bool& getHasBeenHit() { return hasBeenHit; };
private:
	bool hasItem = false;
	bool hasBeenHit = false;
	sf::Texture* itemBlockTexture;

};

