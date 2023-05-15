#include "Cat.h"

Cat::Cat()
{//constructor
	if (!m_catTexture.loadFromFile("ASSETS/IMAGES/cat.png"))
	{
		std::cout << "error with image file";
	}
	m_catSprite.setTexture(m_catTexture);
	m_catSprite.setTextureRect(sf::IntRect(0, GUARD_HEIGHT, GUARD_WIDTH, GUARD_HEIGHT));
	m_catSprite.setOrigin(GUARD_WIDTH / 2, GUARD_HEIGHT / 2);
	m_position = { SCREEN_WIDTH - GUARD_WIDTH,SCREEN_HEIGHT - GUARD_HEIGHT }; //right bottom corner
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
		m_position = sf::Vector2f{ GUARD_WIDTH,GUARD_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ CHARACTER_WIDTH,CHARACTER_HEIGHT })
	{//right top corner 
		m_position = sf::Vector2f{ SCREEN_WIDTH - GUARD_WIDTH,GUARD_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,CHARACTER_HEIGHT })
	{//right bottom corner
		m_position = sf::Vector2f{ SCREEN_WIDTH - GUARD_WIDTH,SCREEN_HEIGHT - GUARD_HEIGHT };
	}
	else if (playerPosition== sf::Vector2f{ SCREEN_WIDTH - CHARACTER_WIDTH,SCREEN_HEIGHT - CHARACTER_HEIGHT })
	{//left bottom corner
		m_position = sf::Vector2f{ GUARD_WIDTH ,SCREEN_HEIGHT - GUARD_HEIGHT };
	}
	m_catSprite.setPosition(m_position);
}
