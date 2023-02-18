#pragma once
#include "Drawable.h"
#include "Platforms.h"

class Staircase : public Platforms
{
public:
	Staircase(sf::Vector2f size);
private:
	sf::Texture* stairBlockTexture;
};

