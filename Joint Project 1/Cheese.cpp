#include "Cheese.h"

Cheese::Cheese()
{//constructor
	m_body.setFillColor(sf::Color::Yellow);
	m_body.setSize(m_size);
	m_body.setPosition(m_position);
	m_body.setOrigin(m_size.x / 2, m_size.y / 2);

	if (!m_texture.loadFromFile("ASSETS/IMAGES/cheese.png"))
	{
		std::cout << "error with image file";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	m_sprite.setOrigin(m_size.x / 2, m_size.y / 2);
	m_sprite.setPosition(m_position);
}

sf::RectangleShape Cheese::getBody()
{
	return m_body;
}

sf::Sprite Cheese::getSprite()
{
	return m_sprite;
}
