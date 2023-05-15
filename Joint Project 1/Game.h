// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include <string>

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "Cheese.h" //include cheese 
#include "Wall.h" //include wall enemy
#include "Guard.h" //include guard enemy
#include "Poison.h" //include poison 
#include "Cat.h" //include cat enemy


class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;
	int gameMode=1; //different game modes
	Player rat; //player
	Cheese cheese; //cheese
	Wall walls[MAX_WALLS]; //wall array
	Guard guards[MAX_GUARDS]; //guard enemy array
	Poison poison; //shooting
	Cat cat; //cat enemy
	sf::Text m_playerLives; //message with players lives
	sf::Text m_closingMessage; //winner or loser message
	sf::Text m_wallLives; //ending screen wall lives message
	sf::RectangleShape button; //return button
	int m_wallsDown = 0; //counts destroyed walls
	int m_playerSelect = 0;
	
	sf::Texture m_instructionTexture; //instruction background texture
	sf::Sprite m_instruction; //instructions screen
	sf::Texture m_chooseCharacterTexture; //choose your character screen texture
	sf::Sprite m_chooseCharacter; //choose your character background
	sf::Texture m_endScreenTexture; //end screen background texture
	sf::Sprite m_endScreen; //end screen background
	sf::Texture m_restartTexture; //restart button texture
	sf::Sprite m_restartButton; //restart button
	sf::Texture m_spriteTexture; //texture to display sprite to choose character
	sf::Sprite m_sprite; //display image 1 to choose character
	sf::Sprite m_sprite2; // display image 2 to choose character
	sf::Texture m_gameplayTexture; //gameplay background texture
	sf::Sprite m_gameplayBackground; //gameplay background

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update(sf::Event t_event);
	void	draw();
	void setupWalls();
	void drawWalls();
	void setupGuards();
	void drawGuards();
	void moveGuards();
	void processMouseButton(sf::Event t_event);
	void setupText();
	void setupBackground();
};
