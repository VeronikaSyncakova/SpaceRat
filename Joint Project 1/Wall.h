#pragma once
//wall enemy class declaraction
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <string>
#include <iostream>

class Wall
{
	sf::RectangleShape m_body;
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	bool m_alive = true;
	int m_lives = 9;
	int m_type; //wich side, N/S/E/W
	sf::Text m_message;
	sf::Font m_font;

public:
	void setupWall(int T_type);
	sf::RectangleShape getBody();
	int getType();
	void decreaseLives(); //decreases lives
	bool getAlive(); //if alive or not
	sf::Text getMessage();
};