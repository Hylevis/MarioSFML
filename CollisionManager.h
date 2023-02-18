#pragma once
//#include "Player.h"
#include "Level.h"

class Level;
class Player;
class CollisionManager
{
private:
	Player* m_Player = nullptr;
	Level* m_Level = nullptr;
	bool IsIntersecting(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2) const;

public:

	CollisionManager(Player* player, Level* level);
	bool CollisionDetection(sf::Clock deltaTime/*, float& ground_Height*/);
};

