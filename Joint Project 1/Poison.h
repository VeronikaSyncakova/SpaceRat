#pragma once
//poison class declaraction
#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include "Wall.h"

class Poison
{
	sf::Texture m_poisonTexture;
	sf::Sprite m_poisonSprite;
	sf::Vector2f m_position;
	int m_direction; //direction of poison
	int m_speed = 4;
	bool m_shooting{ false }; //is it shooting?
public:
	Poison();
	sf::Sprite getSprite();
	void shoot(int t_direction, sf::Vector2f t_position); //move the sprite when shooted
	bool getShooting(); //if it is shooting or not
	void move(); //moves poison in its direction
	void checkWall(Wall t_wall[]); //check collision with wall
	void setShooting();
};