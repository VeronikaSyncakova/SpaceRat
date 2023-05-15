#include "Poison.h"

Poison::Poison()
{//constructor
	if (!m_poisonTexture.loadFromFile("ASSETS/IMAGES/fireball.png"))
	{
		std::cout << "error with poison file";
	}
	m_poisonSprite.setTexture(m_poisonTexture);
	m_poisonSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));//left facing
	m_poisonSprite.setOrigin(POISON / 2.0f, POISON/ 2.0f);
	
}

sf::Sprite Poison::getSprite()
{
	return m_poisonSprite;
}

void Poison::shoot(int t_direction, sf::Vector2f t_position)
{//shooting
	m_position = t_position;
	m_direction = t_direction; //direction to shoot in
	if (m_direction == WEST)
	{
		m_poisonSprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //left facing
		m_position.x -= m_speed; 
	}
	else if (m_direction == EAST)
	{
		m_poisonSprite.setTextureRect(sf::IntRect(0, 4*64, 64, 64));//right facing
		m_position.x += m_speed;
	}
	else if (m_direction == NORTH)
	{
		m_poisonSprite.setTextureRect(sf::IntRect(0, 2 * 64, 64, 64));//up facing
		m_position.y -= m_speed;
	}
	else if (m_direction == SOUTH)
	{
		m_poisonSprite.setTextureRect(sf::IntRect(0, 6 * 64, 64, 64));//down facing
		m_position.y += m_speed;
	}
	m_poisonSprite.setPosition(m_position);
	m_shooting = true; 
}

bool Poison::getShooting()
{
	return m_shooting;
}

void Poison::move()
{ //moves poison in its direction
	if (m_direction == WEST)
	{
		m_position.x -= m_speed;
	}
	else if (m_direction == EAST)
	{
		m_position.x += m_speed;
	}
	else if (m_direction == NORTH)
	{
		m_position.y -= m_speed;
	}
	else if (m_direction == SOUTH)
	{
		m_position.y += m_speed;
	}
	m_poisonSprite.setPosition(m_position);
}

void Poison::checkWall(Wall t_wall[])
{//collision with wall
	for (int i = 0; i < MAX_WALLS; i++)
	{
		if (t_wall[i].getType() == NORTH)
		{
			if (m_poisonSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_shooting = false; //stop shooting
				t_wall[i].decreaseLives();
			}
		}
		else if (t_wall[i].getType() == SOUTH)
		{
			if (m_poisonSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_shooting = false; //stop shooting
				t_wall[i].decreaseLives();
			}
		}
		else if (t_wall[i].getType() == EAST)
		{
			if (m_poisonSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_shooting = false; //stop shooting
				t_wall[i].decreaseLives();

			}
		}
		else if (t_wall[i].getType() == WEST)
		{
			if (m_poisonSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_shooting = false; //stop shooting
				t_wall[i].decreaseLives();
			}
		}
	}

	//screen boundaries check, stop shooting if outside of boundary
	if (m_position.x < 0)
	{
		m_shooting = false;
	}
	else if (m_position.x > SCREEN_WIDTH)
	{
		m_shooting = false;
	}
	else if (m_position.y < 0)
	{
		m_shooting = false;
	}
	else if (m_position.y > SCREEN_HEIGHT)
	{
		m_shooting = false;
	}
}

void Poison::setShooting()
{
	m_shooting = false;
}
