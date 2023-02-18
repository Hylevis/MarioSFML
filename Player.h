#pragma once
#include "Drawable.h"
//#include "CollisionManager.h"
class CollisionManager;
class Player : public Drawable
{
public:
	Player();
	void PlayerUpdate(/*CollisionManager* collisionManager,*/ sf::Clock deltaClock, float ground_Height);
	void damagePlayer();
	void healPlayer();

	float getGroundHeight() { return m_GroundHeight; };
	void setGroundHeight(float groundHeight) { m_GroundHeight = groundHeight; };

	bool getIsJumping() { return m_IsJumping; };
	void setIsJumping(bool isJumping) { m_IsJumping = isJumping; };

	bool getIsBig() { return m_IsBig; };
	void setIsBig(bool isBig) { m_IsBig = isBig; };

	bool getIsDead() { return m_IsDead; };
	void setIsDead(bool isDead) { m_IsDead = isDead; };

	int getHealth() { return m_Health; };
	void setHealth(int health) { m_Health = health; };

	sf::Clock& getJumpClock() { return m_jumpClock; };
	sf::Clock& getInvicibilityFramesClock() { return m_InvincibilityFrames; };

	bool getLevelComplete() { return m_LevelComplete; };
	void setLevelComplete(bool isComplete) { m_LevelComplete = isComplete; };

	void increasePoints(int points) { m_Points += points; };
	int getPoints() { return m_Points; };

private:
	float m_GroundHeight = 0;
	bool m_IsJumping = true;
	bool m_IsBig = false;
	bool m_IsDead = false;
	bool m_LevelComplete = false;
	int m_Health;
	int m_Points = 0;
	sf::Clock m_jumpClock;
	sf::Clock m_InvincibilityFrames;


};

