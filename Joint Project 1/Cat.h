#pragma once
#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include"Player.h"

class Cat
{
	sf::Sprite m_catSprite; //cat sprite
	sf::Texture m_catTexture; //cat enemy texture
	sf::Vector2f m_position; //position of cat enemy
	int m_side; //which side it is facing
	int m_speed{ 2 }; //speed of movement
	int m_direction{DOWN}; //where is going (up or down)

	float m_frameCounter = 0.0f; //which frame
	float m_frameIncrement = 0.25f; // speed of animation
	int m_frame = 0; //chooses frame
	int m_currentFrame{ -1 };

public:
	Cat();
	sf::Sprite getSprite();
	void move(Player& t_player); //follows player
	void reset(Player t_player); //reset for new game
	void animate(); //animates sprite
};