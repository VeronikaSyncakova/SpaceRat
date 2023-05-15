

#include "Player.h"   // include Player header file

// Player function definitions here

void Player::setupSprite()
{
	if (!m_characterTexture.loadFromFile("ASSETS/IMAGES/mouse.png"))
	{
		std::cout << "error with image file";
	}
	m_characterSprite.setTexture(m_characterTexture);
	m_characterSprite.setTextureRect(sf::IntRect(0, 128, 48, 64));//front facing
	m_characterSprite.setPosition(m_position);
	m_characterSprite.setOrigin(CHARACTER_WIDTH / 2.0f, CHARACTER_HEIGHT / 2.0f);
}

Player::Player()
{//constructor
	int num;
	num = (rand() % 4) + 1;

	if (num == 1)
	{ //left top corner
		m_position = sf::Vector2f{ CHARACTER_WIDTH,CHARACTER_HEIGHT };
	}
	else if (num == 2)
	{//right top corner 
		m_position = sf::Vector2f{ SCREEN_WIDTH-CHARACTER_WIDTH,CHARACTER_HEIGHT };
	}
	else if (num == 3)
	{//right bottom corner
		m_position = sf::Vector2f{ SCREEN_WIDTH-CHARACTER_WIDTH,SCREEN_HEIGHT-CHARACTER_HEIGHT };
	}
	else if (num == 4)
	{//left bottom corner
		m_position = sf::Vector2f{ CHARACTER_WIDTH ,SCREEN_HEIGHT-CHARACTER_HEIGHT };
	}
	m_alive = true;
}

void Player::moveUp()
{//moves up
	m_position.y-=m_speed;
	m_direction = NORTH;
	m_characterSprite.setTextureRect(sf::IntRect(0, 0, 48, 64));//north facing
	if (m_position.y <= CHARACTER_HEIGHT/2)
	{//screen boundary check
		m_position.y = CHARACTER_HEIGHT / 2;
	}
	m_characterSprite.setPosition(m_position);
}

void Player::moveDown()
{//moves down
	m_position.y+=m_speed;
	m_direction = SOUTH;
	m_characterSprite.setTextureRect(sf::IntRect(0, 128, 48, 64));//south facing
	if (m_position.y >= SCREEN_HEIGHT - CHARACTER_HEIGHT/2)
	{ //screen boundary check
		m_position.y = SCREEN_HEIGHT - CHARACTER_HEIGHT/2;
	}
	m_characterSprite.setPosition(m_position);
}

void Player::moveLeft()
{//moves left
	m_position.x-=m_speed;
	m_direction = WEST;
	m_characterSprite.setTextureRect(sf::IntRect(0, 192, 48, 64));//west facing
	if (m_position.x <= CHARACTER_WIDTH/2)
	{ //screen boundary check
		m_position.x = CHARACTER_WIDTH / 2;
	}
	m_characterSprite.setPosition(m_position);
}

void Player::moveRight()
{//moves right
	m_position.x+=m_speed;
	m_direction = EAST;
	m_characterSprite.setTextureRect(sf::IntRect(0, 64, 48, 64));//east facing
	if (m_position.x >= SCREEN_WIDTH - CHARACTER_WIDTH/2)
	{ //screen boundary check
		m_position.x = SCREEN_WIDTH - CHARACTER_WIDTH/2;
	}
	m_characterSprite.setPosition(m_position);
}

sf::Sprite Player::getSprite()
{
	return m_characterSprite;
}

void Player::checkWall(Wall t_wall[])
{//collision with walls
	for (int i = 0; i < MAX_WALLS; i++)
	{
		if (t_wall[i].getType() == NORTH)
		{//north wall
			if (m_characterSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_position.y = 330 - (CHARACTER_HEIGHT / 2);
			}
		}
		else if (t_wall[i].getType() == SOUTH)
		{//south wall
			if (m_characterSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_position.y = 470 + (CHARACTER_HEIGHT / 2);
			}
		}
		else if (t_wall[i].getType() == EAST)
		{//east wall
			if (m_characterSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_position.x = 820 + (CHARACTER_WIDTH / 2);
			}
		}
		else if (t_wall[i].getType() == WEST)
		{//west wall
			if (m_characterSprite.getGlobalBounds().intersects(t_wall[i].getBody().getGlobalBounds()))
			{
				m_position.x = 680 - (CHARACTER_WIDTH / 2);
			}
		}
	}
	m_characterSprite.setPosition(m_position);
}

void Player::checkGuard(Guard t_guard[])
{//collision with guards
	for (int i = 0; i < MAX_GUARDS; i++)
	{
		if (t_guard[i].getType() == NORTH)
		{//north guard
			if (m_characterSprite.getGlobalBounds().intersects(t_guard[i].getSprite().getGlobalBounds()))
			{
				m_lives--;
				//relocates outside of the guard line of movement
				if (m_position.y <= t_guard[i].getPosition().y)
				{
					m_position.y -= CHARACTER_HEIGHT;
				}
				if (m_position.y >= t_guard[i].getPosition().y)
				{
					m_position.y += CHARACTER_HEIGHT;
				}
			}
		}
		else if (t_guard[i].getType() == SOUTH)
		{//south guard
			if (m_characterSprite.getGlobalBounds().intersects(t_guard[i].getSprite().getGlobalBounds()))
			{
				m_lives--;
				//relocates outside of the guard line of movement
				if (m_position.y <= t_guard[i].getPosition().y)
				{
					m_position.y -= CHARACTER_HEIGHT;
				}
				if (m_position.y >= t_guard[i].getPosition().y)
				{
					m_position.y += CHARACTER_HEIGHT;
				}
			}
		}
		else if (t_guard[i].getType() == EAST)
		{//east guard
			if (m_characterSprite.getGlobalBounds().intersects(t_guard[i].getSprite().getGlobalBounds()))
			{
				m_lives--;
				//relocates outside of the guard line of movement
				if (m_position.x <= t_guard[i].getPosition().x)
				{
					m_position.x -= CHARACTER_HEIGHT;
				}
				if (m_position.x >= t_guard[i].getPosition().x)
				{
					m_position.x += CHARACTER_HEIGHT;
				}

			}
		}
		else if (t_guard[i].getType() == WEST)
		{//west guard
			if (m_characterSprite.getGlobalBounds().intersects(t_guard[i].getSprite().getGlobalBounds()))
			{
				m_lives--;
				//relocates outside of the guard line of movement
				if (m_position.x <= t_guard[i].getPosition().x)
				{
					m_position.x -= CHARACTER_HEIGHT;
				}
				if (m_position.x >= t_guard[i].getPosition().x)
				{
					m_position.x += CHARACTER_HEIGHT;
				}

			}
		}
		m_characterSprite.setPosition(m_position);
	}

	if (m_lives == 0) //player died
	{
		m_alive = false;
	}
}

void Player::checkCheese(sf::RectangleShape t_cheese)
{//collision with cheese
	if (m_characterSprite.getGlobalBounds().intersects(t_cheese.getGlobalBounds()))
	{//player won
		m_alive = false;
	}
}

void Player::setAlive()
{
	
	m_lives = 0;
}

void Player::reset()
{//starting new game
	m_alive = true;
	m_lives = 3;
	
	int num;
	num = (rand() % 4) + 1;

	if (num == 1)
	{ //left top corner
		m_position = sf::Vector2f{ CHARACTER_WIDTH,CHARACTER_HEIGHT };
	}
	else if (num == 2)
	{//right top corner 
		m_position = sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,CHARACTER_HEIGHT };
	}
	else if (num == 3)
	{//right bottom corner
		m_position = sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,SCREEN_HEIGHT - CHARACTER_HEIGHT };
	}
	else if (num == 4)
	{//left bottom corner
		m_position = sf::Vector2f{ CHARACTER_WIDTH ,SCREEN_HEIGHT - CHARACTER_HEIGHT };
	}
	m_characterSprite.setTextureRect(sf::IntRect(0, 128, 48, 64));//front facing
	m_characterSprite.setPosition(m_position);
}

void Player::chooseCharacter(int t_playerSelect)
{//choosing sprites
	if (t_playerSelect == 2)
	{
		m_characterSprite.setColor(sf::Color::Magenta);
	}
	else
	{
		m_characterSprite.setColor(sf::Color::White);

	}
}

int Player::getDirection()
{
	return m_direction;
}

sf::Vector2f Player::getPosition()
{
	return m_position;
}

bool Player::getAlive()
{
	return m_alive;
}

int Player::getLives()
{
	return m_lives;
}