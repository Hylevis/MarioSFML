#include "Enemy.h"


Enemy::Enemy(float x_Min, float x_Max, bool isGoomba)
	:m_XMin(x_Min)
	,m_XMax(x_Max)
	,m_isGoomba(isGoomba)
{	
	setAccelerationX(0);
	if (isGoomba)
	{
		if (!getTexture().loadFromFile("goomba.png"))
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
	else
	{
		if (!getTexture().loadFromFile("koopa.png"))
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

		if (!m_ShellTexture.loadFromFile("koopashell.png"))
		{
			sf::Sprite error_Sprite;
			error_Sprite.setColor(sf::Color::Magenta);
			getSprite() = error_Sprite;
		}
		else
		{
			m_ShellTexture.setSmooth(true);
			m_ShellSprite.setTexture(m_ShellTexture);
			m_ShellSprite = sf::Sprite(m_ShellTexture);
			m_ShellSprite.scale(.3f, .5f);
			m_ShellSprite.setOrigin(m_ShellTexture.getSize().x / 2.f, m_ShellTexture.getSize().y / 2.f);
			m_ShellHitbox.setFillColor(sf::Color::Red);
			m_ShellHitbox.setSize(sf::Vector2f(m_ShellTexture.getSize().x * m_ShellSprite.getScale().x, m_ShellTexture.getSize().y * m_ShellSprite.getScale().y));
			m_ShellHitbox.setOrigin(m_ShellHitbox.getSize().x / 2, m_ShellHitbox.getSize().y / 2);
			m_ShellHitbox.setPosition(m_ShellSprite.getPosition());
		}
	}
	
}
void Enemy::Update()
{
	getHitbox().setPosition(getSprite().getPosition());
	if (getSprite().getPosition().x > m_XMax && !m_IsShell)
	{

		//getSprite().setScale(-.1f, .1f);
		m_goingRight = false;

	}
	else if (getSprite().getPosition().x > m_XMax && m_IsShell)
	{
		setVelocityX(-4);
		m_goingRight = false;

	}
	else if (getSprite().getPosition().x < m_XMin && !m_IsShell)
	{

		getSprite().setScale(.1f, .1f);
		m_goingRight = true;

	}

	if (m_goingRight && !m_IsShell)
	{
		//getSprite().setScale(.1f, .1f);
		if (getVelocityX() > -5)
		{
			setVelocityX(2);
		}
	}
	else if (!m_goingRight && !m_IsShell)
	{
		getSprite().setScale(-.1f, .1f);
		if (getVelocityX() < 5)
		{
			setVelocityX(-2);
		}
	}


	Move(getSprite().getPosition().y);


}