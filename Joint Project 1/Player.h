// Player class declaration
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include "Wall.h"
#include "Guard.h"

class Player
{
	// private data members
	sf::Sprite m_characterSprite;
	sf::Texture m_characterTexture;
	sf::Vector2f m_position; //position of player
	int m_direction; //direction of player
	int m_speed = 4; //speed of the player
	int m_lives = 3; //lives
	bool m_alive; //alive or not


public:
	Player();
	void setupSprite(); 
	void moveUp(); //move the player up
	void moveDown(); //move the player down
	void moveLeft(); //move the player left
	void moveRight(); //move the player right
	sf::Sprite getSprite(); //returns sprite
	void checkWall(Wall t_wall[]); //checks if thee is wall
	void checkGuard(Guard t_guard[]); //collision with guard
	int getDirection(); 
	sf::Vector2f getPosition();
	bool getAlive(); //alive or not
	int getLives(); //returns lives
	void checkCheese(sf::RectangleShape t_cheese); //checks if player wins
	void setAlive(); //set if alive or dead
	void reset(); //resets player
	void chooseCharacter(int t_playerSelect);
};