#include "Guard.h"

void Guard::setupGuard(int t_type)
{
	m_type = t_type + 1;
	if (!m_guardTexture.loadFromFile("ASSETS/IMAGES/enemy2.png"))
	{
		std::cout << "error with image file";
	}
	m_guardSprite.setTexture(m_guardTexture);
	
	//set the position on the screen and assign type
	if (m_type == NORTH)
	{
		m_guardSprite.setTextureRect(sf::IntRect(0, 2*GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
		m_position = { 750.0f, 200.0f };
		m_side = RIGHT; //which direction it is currently going in
	}
	else if (m_type == SOUTH)
	{
		m_guardSprite.setTextureRect(sf::IntRect(0, GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
		m_position = { 750.0f, 600.0f };
		m_side = LEFT;  //which direction it is currently going in
	}
	else if (m_type == EAST)
	{
		m_guardSprite.setTextureRect(sf::IntRect(0, 0, GUARD_WIDTH, GUARD_HEIGHT));
		m_position = { 950.0f, 400.0f };
		m_side = DOWN;  //which direction it is currently going in
	}
	else if (m_type == WEST)
	{
		m_guardSprite.setTextureRect(sf::IntRect(0, 3*GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
		m_position = { 550.0f, 400.0f };
		m_side = UP;  //which direction it is currently going in
	}
	
	m_guardSprite.setPosition(m_position);
	m_guardSprite.setOrigin(GUARD_WIDTH/2,GUARD_HEIGHT/2);
}

sf::Sprite Guard::getSprite()
{
	return m_guardSprite;
}

void Guard::moveGurad()
{
	if (m_type == NORTH || m_type==SOUTH)
	{
		if (m_side == RIGHT)
		{
			if (m_position.x < 950)
			{
				m_position.x += m_speed;
			}
			else
			{//reaches boundary and switches to another direction
				m_position.x = 950;
				m_side = LEFT;
				m_guardSprite.setTextureRect(sf::IntRect(0, GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
			}
		}
		if (m_side == LEFT)
		{
			if (m_position.x > 550)
			{
				m_position.x -= m_speed;
			}
			else//reaches boundary and switches to another direction
			{
				m_position.x = 550;
				m_side = RIGHT;
				m_guardSprite.setTextureRect(sf::IntRect(0, 2 * GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
			}
		}
	}
	else if (m_type == EAST || m_type ==WEST)
	{
		if (m_side == DOWN)
		{
			if (m_position.y < 600)
			{
				m_position.y += m_speed;
			}
			else
			{//reaches boundary and switches to another direction
				m_position.y = 600;
				m_side = UP;
				m_guardSprite.setTextureRect(sf::IntRect(0, 3 * GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
			}
		}
		if (m_side == UP)
		{
			if (m_position.y > 200)
			{
				m_position.y -= m_speed;
			}
			else
			{//reaches boundary and switches to another direction
				m_position.y = 200;
				m_side = DOWN;
				m_guardSprite.setTextureRect(sf::IntRect(0, 0, GUARD_WIDTH, GUARD_HEIGHT));
			}
		}
	}
	m_guardSprite.setPosition(m_position);
}

int Guard::getType()
{
	return m_type;
}

sf::Vector2f Guard::getPosition()
{
	return m_position;
}
