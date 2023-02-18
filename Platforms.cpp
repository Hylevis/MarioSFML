#include "Platforms.h"
#include "Player.h"

Platforms::Platforms(sf::RectangleShape shape)
	:m_Platform(shape)
{

}

Platforms::Platforms(sf::RectangleShape shape, bool isground)
	: m_Platform(shape)
	,m_isGround(isground)
{

}
Platforms::Platforms()
{

}

