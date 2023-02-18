#include "Drawable.h"


void Drawable::Move(float ground_Height)
{
	float gravity = .5;

	if (m_Sprite.getPosition().y < ground_Height && m_velocityY < 20)                  //If you are above ground
		m_velocityY += gravity;    //Add gravity
	//else if (m_Sprite.getPosition().y > ground_Height)             //If you are below ground
		//m_Sprite.setPosition(m_Sprite.getPosition().x,ground_Height);                 //That's not supposed to happen, put him back up

	//m_velocityX += m_accelerationX;
	//m_velocityY += m_accelerationY;

	m_Sprite.setPosition(m_Sprite.getPosition().x + m_velocityX, m_Sprite.getPosition().y);
	m_Sprite.setPosition(m_Sprite.getPosition().x, m_Sprite.getPosition().y + m_velocityY);
}

void Drawable::Draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);
}