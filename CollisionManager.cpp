#include "CollisionManager.h"


CollisionManager::CollisionManager(Player* player, Level* level)
{
	m_Player = player;
	m_Level = level;

}

bool CollisionManager::IsIntersecting(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2) const
{
	return (abs(shape1.getPosition().x - shape2.getPosition().x) * 2.f <= (shape1.getSize().x + shape2.getSize().x)) &&
		(abs(shape1.getPosition().y - shape2.getPosition().y) * 2.f <= (shape1.getSize().y + shape2.getSize().y));
}

//bool CollisionManager::CollisionDetection(sf::Clock deltaTime/*, float& ground_Height*/)
//{
	//Player* destinationShape = m_Player;
	//if (deltaTime.getElapsedTime().asMilliseconds() != 0)
	//{
	//	destinationShape->Move(destinationShape->getGroundHeight());
	//}
	/*for (int i = 0; i < m_Level->m_Platforms.size(); i++)
	{
		if (m_Level->m_Platforms[i]->m_isItemBlock || m_Level->m_Platforms[i]->m_isBrickBlock)
		{
			//top collision
			if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35);
				ground_Height = m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35;
				m_Player->m_IsJumping = false;
				m_Player->m_jumpClock.restart();
			}
			//left collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x <= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + 100)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x - 47, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//right collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x >= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + 100)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x + 147, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//bottom collision
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y > m_Level->m_Platforms[i]->m_Platform.getPosition().y + 5)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Player->m_Sprite.getPosition().y + 5);
				m_Player->m_velocityY = 0;
			}
		}
		else if (m_Level->m_Platforms[i]->m_isGround == true)
		{
			//top collision
			if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35);
				ground_Height = m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35;
				m_Player->m_IsJumping = false;
				m_Player->m_jumpClock.restart();
			}
			//left collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x <= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + 400)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x - 47, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//right collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x >= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + 400)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x + 1047, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//bottom collision
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y > m_Level->m_Platforms[i]->m_Platform.getPosition().y + 5)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Player->m_Sprite.getPosition().y + 5);
				m_Player->m_velocityY = 0;
			}
		}
		else if (m_Level->m_Platforms[i]->m_isPipe == true)
		{
			//top collision
			if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35);
				ground_Height = m_Level->m_Platforms[i]->m_Platform.getPosition().y - 35;
				m_Player->m_IsJumping = false;
				m_Player->m_jumpClock.restart();
			}
			//left collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x <= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + m_Level->m_Platforms[i]->m_Platform.getSize().y)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x - 47, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//right collsion
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().x >= m_Level->m_Platforms[i]->m_Platform.getPosition().x && m_Player->m_Sprite.getPosition().y < m_Level->m_Platforms[i]->m_Platform.getPosition().y + 200 + m_Level->m_Platforms[i]->m_Platform.getSize().y)
			{
				m_Player->m_Sprite.setPosition(m_Level->m_Platforms[i]->m_Platform.getPosition().x + 247, m_Player->m_Sprite.getPosition().y);
				m_Player->m_velocityX = 0;
				m_Player->m_velocityY = 5;
			}
			//bottom collision
			else if (m_Player->m_Sprite.getGlobalBounds().intersects(m_Level->m_Platforms[i]->m_Platform.getGlobalBounds()) && m_Player->m_Sprite.getPosition().y > m_Level->m_Platforms[i]->m_Platform.getPosition().y + 5)
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Player->m_Sprite.getPosition().y + 5);
				m_Player->m_velocityY = 0;
			}
		}
	}
	*/
	/*for (int i = 0; i < m_Level->m_Level.m_Platforms.size(); i++)
	{
		if(destinationShape->m_Hitbox.getGlobalBounds().intersects(m_Level->m_Level.m_Platforms[i]->m_Platform.getGlobalBounds()))
		{
			//bottom collision
			if (destinationShape->m_Sprite.getGlobalBounds().top < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top
				&& destinationShape->m_Sprite.getGlobalBounds().top + destinationShape->m_Sprite.getGlobalBounds().height < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().height
				&& destinationShape->m_Sprite.getGlobalBounds().top < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().height
				&& destinationShape->m_Sprite.getGlobalBounds().left + destinationShape->m_Sprite.getGlobalBounds().width > m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left
				)
			{
				//destinationShape->m_velocityY = 0.f;
				m_Player->m_GroundHeight = m_Level->m_Level.m_Platforms[i].m_Platform.getPosition().y - 35;
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Level->m_Level.m_Platforms[i].m_Platform.getPosition().y - 35);
			}
			//Top collision
			else if (destinationShape->m_Hitbox.getGlobalBounds().top > m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top
				&& destinationShape->m_Sprite.getGlobalBounds().top + destinationShape->m_Sprite.getGlobalBounds().height > m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().height
				&& destinationShape->m_Sprite.getGlobalBounds().left < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().width
				&& destinationShape->m_Sprite.getGlobalBounds().left + destinationShape->m_Sprite.getGlobalBounds().width > m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left
				)
			{
				//destinationShape->m_velocityY = 0.f;
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getGlobalBounds().left, m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top - destinationShape->m_Sprite.getGlobalBounds().height);
			}

			else if (destinationShape->m_Sprite.getGlobalBounds().left < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left
				&& destinationShape->m_Sprite.getGlobalBounds().left + destinationShape->m_Sprite.getGlobalBounds().width < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().width
				&& destinationShape->m_Sprite.getGlobalBounds().top  < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().height
				&& destinationShape->m_Sprite.getGlobalBounds().top + destinationShape->m_Sprite.getGlobalBounds().height < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top 
				)
			{
				//destinationShape->m_velocityX = 0.f;
				m_Player->m_Sprite.setPosition(m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left - m_Player->m_Sprite.getGlobalBounds().width, m_Player->m_Sprite.getGlobalBounds().top);
			}
			//left collision
			else if (destinationShape->m_Sprite.getGlobalBounds().left < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left
				&& destinationShape->m_Sprite.getGlobalBounds().left + destinationShape->m_Sprite.getGlobalBounds().width > m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().width
				&& destinationShape->m_Sprite.getGlobalBounds().top < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top + m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().height
				&& destinationShape->m_Sprite.getGlobalBounds().top + destinationShape->m_Sprite.getGlobalBounds().height < m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().top
				)
			{
				//destinationShape->m_velocityX = 0.f;
				m_Player->m_Sprite.setPosition(m_Level->m_Level.m_Platforms[i].m_Platform.getGlobalBounds().left + m_Player->m_Sprite.getGlobalBounds().width, m_Player->m_Sprite.getGlobalBounds().top);
			}
			
			if (destinationShape->m_Sprite.getGlobalBounds().contains(m_Level->m_Level.m_Platforms[i]->m_Platform.getPosition()))
			{
				m_Player->m_Sprite.setPosition(m_Player->m_Sprite.getPosition().x, m_Level->m_Level.m_Platforms[i]->m_Platform.getPosition().y - 45);
			}
			//return true;
		}
	}*/
	//return false;

//}
