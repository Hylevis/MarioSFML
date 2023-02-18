#pragma once
#include "Drawable.h"

class Player;

class Platforms : public Drawable
{
public:

	Platforms(sf::RectangleShape shape);
	Platforms(sf::RectangleShape shape, bool isground);
	Platforms();

	bool& getIsItemBlock() { return m_isItemBlock; };

	bool& getIsBrickBlock() { return m_isBrickBlock; };

	bool& getIsPipe() { return m_isPipe; };

	bool& getIsFlag() { return m_isFlag; };

	bool& getIsGround() { return m_isGround; };

	sf::RectangleShape& getPlatform() { return m_Platform; };

private:
	sf::RectangleShape m_Platform;
	bool m_isGround = false;
	bool m_isItemBlock = false;
	bool m_isBrickBlock = false;
	bool m_isPipe = false;
	bool m_isFlag = false;


};

