#pragma once
#include "Platforms.h"

class Pipe : public Platforms
{
public:
	Pipe(sf::Vector2f size);

private:
	sf::Texture* m_PipeTexture;
};

