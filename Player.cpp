#include "Player.h"
#include "CollisionManager.h"

Player::Player()
{
	m_Health = 1;
	if (!getTexture().loadFromFile("Mario.png"))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		getSprite() = error_Sprite;
	}
	else
	{
		getTexture().setSmooth(true);
		getSprite().setTexture(getTexture());
		getSprite() = sf::Sprite(getTexture());
		getSprite().scale(.1f, .1f);
		getSprite().setOrigin(getTexture().getSize().x / 2.f, getTexture().getSize().y / 2.f);
		getHitbox().setFillColor(sf::Color::Red);
		getHitbox().setSize(sf::Vector2f(getTexture().getSize().x * getSprite().getScale().x, getTexture().getSize().y * getSprite().getScale().y));
		getHitbox().setOrigin(getHitbox().getSize().x / 2, getHitbox().getSize().y / 2);
		getHitbox().setPosition(getHitbox().getPosition());

	}
}

void Player::damagePlayer()
{
	m_Health--;
}

void Player::healPlayer()
{
	m_Health++;
}

void Player::PlayerUpdate(/*CollisionManager* collisionManager,*/ sf::Clock deltaClock, float ground_Height)
{
	getHitbox().setPosition(getSprite().getPosition());

	if (m_Health <= 0)
	{
		m_IsDead = true;; // game over
	}
	else if (m_Health == 1)
	{
		m_IsBig = false;
	}
	else if (m_Health >= 2)
	{
		m_IsBig = true;
	}

	if (getSprite().getPosition().y < 750 && getVelocityY() == 0)
	{
		setVelocityY(4);
	}
	//else if(getSprite().getPosition().y <= 17.5 && m_velocityY == 0)
	//{
	//	getSprite().setPosition(getSprite().getPosition().x, 2);
	//}


	if (m_IsBig)
	{
		getSprite().setScale(getSprite().getScale().x, .15f);
	}
	else
	{
		getSprite().setScale(getSprite().getScale().x, .1f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (getVelocityX() > -5 && getSprite().getPosition().x > 500)
		{
			setVelocityX(getVelocityX() -= deltaClock.getElapsedTime().asSeconds() * getAccelerationX());
		}
		if (getSprite().getScale().x != -.1f)
		{
			getSprite().setScale(getSprite().getScale().x * -1, getSprite().getScale().y);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (getVelocityX() < 5)
		{
			getVelocityX() += deltaClock.getElapsedTime().asSeconds() * getAccelerationX();
		}
		if (getSprite().getScale().x != .1f)
		{
			getSprite().setScale(getSprite().getScale().x * -1, getSprite().getScale().y);
		}

	}
	else
	{
		if (getVelocityX() <= -1)
		{
			getVelocityX() += deltaClock.getElapsedTime().asSeconds() * getAccelerationX();
		}
		else if (getVelocityX() <= -1 && getVelocityX() < 0)
		{
			getVelocityX() = 0;
		}
		else if (getVelocityX() >= 1)
		{
			getVelocityX() -= deltaClock.getElapsedTime().asSeconds() * getAccelerationX();
		}
		else
		{
			getVelocityX() = 0;
		}
	}

	/*if (!collisionManager->CollisionDetection(deltaClock, ground_Height))
	{
		Move(ground_Height);
	}
	*/
	Move(ground_Height);
}