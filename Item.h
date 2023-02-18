#pragma once
#include "Drawable.h"

class Platforms;

class Item : public Drawable
{
public:
	Item(bool isMushroom);

	void Update(std::vector<Platforms*> platforms);

	bool& getIsDead() { return m_IsDead; };

	bool getIsMushroom() { return m_IsMushroom; };

	sf::Clock& getSpawnTimer() { return m_SpawnTimer; };
	bool m_IsStaticCoin = false;
private:
	float m_GroundHeight;
	bool m_IsMushroom;
	bool m_IsDead = false;

	sf::Clock m_SpawnTimer;
};

