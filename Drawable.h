#pragma once
#include <SFML/Graphics.hpp>

class Drawable
{
public:
	virtual void Move(float ground_Height);
	void Draw(sf::RenderWindow& window);

	sf::Sprite& getSprite() { return m_Sprite; };

	sf::Texture& getTexture() { return m_Texture; };

	sf::RectangleShape& getHitbox() { return m_Hitbox; };

	float& getVelocityX() { return m_velocityX; };
	void setVelocityX(float speed) { m_velocityX = speed; };

	float getVelocityY() { return m_velocityY; };
	void setVelocityY(float speed) { m_velocityY = speed; };

	float getAccelerationX() { return m_accelerationX; };
	void setAccelerationX(float speed) { m_accelerationX = speed; };

private:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	sf::RectangleShape m_Hitbox;
	float m_velocityX = 0;
	float m_velocityY = 0;
	float m_accelerationX = 1000;
	float m_accelerationY = 1000;

};

