#include "Item.h"
#include "Platforms.h"


Item::Item(bool isMushroom)
	:m_IsMushroom(isMushroom)
{
	
	if (isMushroom)
	{
		if (!getTexture().loadFromFile("mushroom.png"))
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
			getSprite().scale(.35f, .35f);
			getSprite().setOrigin(getTexture().getSize().x / 2.f, getTexture().getSize().y / 2.f);
			getHitbox().setFillColor(sf::Color::Red);
			getHitbox().setSize(sf::Vector2f(getTexture().getSize().x * getSprite().getScale().x, getTexture().getSize().y * getSprite().getScale().y));
			getHitbox().setOrigin(getHitbox().getSize().x / 2, getHitbox().getSize().y / 2);
			getHitbox().setPosition(getSprite().getPosition());

		}
	}
	else
	{
		if (!getTexture().loadFromFile("coin.png"))
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
			getHitbox().setPosition(getSprite().getPosition());

		}
	}
}

void Item::Update(std::vector<Platforms*> m_Platforms)
{
	if (m_IsMushroom)
	{
		if (m_SpawnTimer.getElapsedTime().asSeconds() < 1)
		{
			setVelocityY(-.5f);

		}
		else if (getVelocityX() == 0)
		{

			setVelocityX(2);
		}
		else
		{
			setVelocityY(4);
		}

		Move(m_GroundHeight);
	}
	else if (!m_IsStaticCoin)
	{
		if (m_SpawnTimer.getElapsedTime().asSeconds() < .5)
		{
			setVelocityY(-4.f);

		}
		else
		{
			m_IsDead = true;
		}
		Move(m_GroundHeight);
	}

}