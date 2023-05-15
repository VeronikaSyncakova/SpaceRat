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

	float m_frameCounter = 0.0f; //which frame
	float m_frameIncrement = 0.15f; // speed of animation
	int m_frame = 0; //chooses frame
	int m_currentFrame{ -1 };
	int m_row = 0;
	int m_col = 0;

public:
	Cheese();
	sf::RectangleShape getBody();
	sf::Sprite getSprite();
	void animate();
};