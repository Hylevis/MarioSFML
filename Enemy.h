#pragma once
#include "Drawable.h"

class Enemy : public Drawable
{
public:
	Enemy(float x_Min, float x_Max, bool isGoomba);
	void Update();

	bool& getIsGoomba() { return m_isGoomba; };

	bool& getIsShell() { return m_IsShell; };

	bool& getIsDead() { return m_IsDead; };
	void setIsDead(bool isDead) { m_IsDead = isDead; };

	sf::Clock& getShellHitCD() { return m_ShellHitCD; };

	sf::Clock& getShellHitBoxCD() { return m_ShellHitBoxCD; };

	sf::Sprite& getShellSprite() { return m_ShellSprite; };
private:
	float m_XMin;
	float m_XMax;
	float m_GroundHeight = 0;
	sf::Texture m_ShellTexture;
	sf::Sprite m_ShellSprite;
	sf::RectangleShape m_ShellHitbox;
	sf::Clock m_ShellHitCD;
	sf::Clock m_ShellHitBoxCD;
	bool m_IsDead = false;
	bool m_IsShell = false;
	bool m_goingRight = false;
	bool m_isGoomba;
};

