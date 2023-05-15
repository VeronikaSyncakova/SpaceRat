#pragma once
//cheese class declaraction
#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Globals.h"

class Cheese
{
	sf::RectangleShape m_body;
	sf::Vector2f m_size{50.0f, 50.0f};
	sf::Vector2f m_position{SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f};

	sf::Texture m_texture; 
	sf::Sprite m_sprite; 
public:
	Cheese();
	sf::RectangleShape getBody();
	sf::Sprite getSprite();
};