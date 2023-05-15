#pragma once
#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Globals.h"

class Guard
{
	sf::Texture m_guardTexture;
	sf::Sprite m_guardSprite;
	sf::Vector2f m_position;
	int m_type; //which side it is (N,S,E,W)
	int m_side; //what direction are they facing
	int m_speed{ 1 }; //seed of movement

	float m_frameCounter = 0.0f; //which frame
	float m_frameIncrement = 0.3f; // speed of animation
	int m_frame = 0; //chooses frame
	int m_currentFrame{ -1 };

public:
	void setupGuard(int t_type);
	sf::Sprite getSprite();
	void moveGurad();
	int getType(); //returns which side it is on
	sf::Vector2f getPosition();
	void animate(); //animates sprite
};