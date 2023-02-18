#pragma once
#include "Player.h"
#include <vector>
#include "Platforms.h"

class Enemy;
class Item;

class Level
{

public:
	Level();
	~Level();
	void Collision(float& ground_Height, Player& player1);
	void drawLevel(sf::RenderWindow& window);
	void downPipe(Player& player1, bool isDown);

private:
	std::vector<Platforms*> m_Platforms;
	std::vector<Enemy*> m_Enemies;
	std::vector<sf::RectangleShape*> m_Holes;
	std::vector<Item*> m_Items;
	//std::vector<Enemy*> m_Enemies;
	sf::Texture* m_GroundTexture;
	sf::Texture* m_HitBlockTexture;


};

