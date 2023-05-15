#include "Cat.h"

Cat::Cat()
{//constructor
	if (!m_catTexture.loadFromFile("ASSETS/IMAGES/cat.png"))
	{
		std::cout << "error with image file";
	}
	m_catSprite.setTexture(m_catTexture);
	m_catSprite.setTextureRect(sf::IntRect(0, CAT_HEIGHT, CAT_WIDTH, CAT_HEIGHT));
	m_catSprite.setOrigin(CAT_WIDTH / 2.0f, CAT_HEIGHT / 2.0f);
	m_position = { SCREEN_WIDTH - CAT_WIDTH,SCREEN_HEIGHT - CAT_HEIGHT }; //right bottom corner
	m_catSprite.setPosition(m_position);
}

sf::Sprite Cat::getSprite()
{
	return m_catSprite;
}

void Cat::move(Player& t_player)
{//following the player
	sf::Vector2f displacement;
	float length;
	displacement.x = t_player.getPosition().x - m_position.x;
	displacement.y = t_player.getPosition().y - m_position.y;
	length = std::sqrtf(displacement.x * displacement.x + displacement.y * displacement.y);
	displacement = displacement / length;
	displacement = displacement * static_cast<float>(m_speed);
	m_position += displacement;
	m_catSprite.setPosition(m_position);

	if (displacement.y > 0)
	{
		m_direction = DOWN;
	}
	else
	{
		m_direction = UP;
	}

	if (m_catSprite.getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
	{//collision between cat and player
		t_player.setAlive();
	}
	
}

void Cat::reset(Player t_player)
{
	sf::Vector2f playerPosition = t_player.getPosition();

	if (playerPosition == sf::Vector2f{CHARACTER_WIDTH, SCREEN_HEIGHT - CHARACTER_HEIGHT})
	{ //left top corner
		m_position = sf::Vector2f{ CAT_WIDTH,CAT_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ CHARACTER_WIDTH,CHARACTER_HEIGHT })
	{//right top corner 
		m_position = sf::Vector2f{ SCREEN_WIDTH - CAT_WIDTH,CAT_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,CHARACTER_HEIGHT })
	{//right bottom corner
		m_position = sf::Vector2f{ SCREEN_WIDTH - CAT_WIDTH,SCREEN_HEIGHT - CAT_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,SCREEN_HEIGHT - CHARACTER_HEIGHT })
	{//left bottom corner
		m_position = sf::Vector2f{ CAT_WIDTH ,SCREEN_HEIGHT - CAT_HEIGHT };
	}
	m_catSprite.setPosition(m_position);
}

void Cat::animate()
{
	m_frameCounter += m_frameIncrement;
	m_frame = static_cast<int>(m_frameCounter);
	if (m_direction == UP)
	{
		if (m_frame > 8 - 1)
		{
			m_frame = 0;
			m_frameCounter -= 8.0f;
		}
		if (m_frame != m_currentFrame)
		{
			m_currentFrame = m_frame;
			m_catSprite.setTextureRect(sf::IntRect(m_frame * CAT_WIDTH, 192, CAT_WIDTH, CAT_HEIGHT));
		}
	}

	if (m_direction == DOWN)
	{
		if (m_frame > 8 - 1)
		{
			m_frame = 0;
			m_frameCounter -= 8.0f;
		}
		if (m_frame != m_currentFrame)
		{
			m_currentFrame = m_frame;
			m_catSprite.setTextureRect(sf::IntRect(m_frame * CAT_WIDTH, 0, CAT_WIDTH, CAT_HEIGHT));
		}
	}
}
