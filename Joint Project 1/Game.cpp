// Name: Veronika Sybcakova
// Login: c00288340
// Date: 20/03/2023
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
	srand((int)time(nullptr)); // set the seed once

}

void Game::loadContent()
// Load the font file & setup the message string
{
	
	setupBackground();
	setupText();
	rat.setupSprite();
	setupWalls();
	setupGuards();
}


void Game::run()
// This function contains the main game loop which controls the game. 
{



	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		processMouseButton(event);
		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update(event);
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update(sf::Event t_event)
// This function takes the keyboard input and updates the game world
{
	//game modes
	if (gameMode == INSTRUCTIONS)
	{//instructions
		if (t_event.type == sf::Event::KeyReleased)
		{
			if (t_event.key.code == sf::Keyboard::Enter)
			{
				gameMode = 2;
			}
		}
	}
	else if (gameMode == CHOOSE_CHARACTER)
	{//choosing character
	}
	else if (gameMode == GAME_PLAY)
	{//game play
		// get keyboard input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				rat.moveLeft();
				rat.animate();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rat.moveRight();
				rat.animate();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				rat.moveUp();
				rat.animate();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				rat.moveDown();
				rat.animate();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
					if (!poison.getShooting())
					{//shooting
						poison.shoot(rat.getDirection(), rat.getPosition());
					}
			}
		rat.checkWall(walls); //collision check between walls and player
		rat.checkGuard(guards); //collision check between guards and player
		moveGuards();
		cat.move(rat);
		cat.animate();
		cheese.animate();
		rat.checkCheese(cheese.getBody()); //collision check between cheese and player
		if (poison.getShooting())
		{ //shooting
			poison.move();
			poison.checkWall(walls); //collision check between walls and poison
		}

	}
	else if (gameMode == CLOSING_SCREEN)
	{//closing screen
		button.setFillColor(sf::Color::Red);
		button.setSize(sf::Vector2f{ 200.0f,80.0f });
		button.setOrigin(100.0f, 40.0f);
		button.setPosition(SCREEN_WIDTH / 2,600 );
		m_restartButton.setOrigin(button.getOrigin());
		m_restartButton.setPosition(button.getPosition());

		m_closingMessage.setOrigin(m_closingMessage.getGlobalBounds().width / 2, m_closingMessage.getGlobalBounds().height / 2);
		m_playerLives.setCharacterSize(40);
		m_playerLives.setOrigin(m_playerLives.getGlobalBounds().width / 2, m_playerLives.getGlobalBounds().height / 2);
		m_playerLives.setPosition(SCREEN_WIDTH / 2, 400.0f);

		m_wallsDown = 4; //how many walls are destroyed
		for (int i = 0; i < MAX_WALLS; i++)
		{
			if (walls[i].getAlive())
			{
				m_wallsDown--;
			}
		}
		m_wallLives.setString("Walls down: " + std::to_string(m_wallsDown));

		if (rat.getLives() == 0) //player died
		{
			m_closingMessage.setString("Game Over");
			m_playerLives.setString("");
		}
		else //player won
		{
			m_closingMessage.setString("Winner");
			m_playerLives.setString("Lives left: " + std::to_string(rat.getLives()));
		}

		m_wallLives.setCharacterSize(40);
		m_wallLives.setOrigin(m_wallLives.getGlobalBounds().width / 2, m_wallLives.getGlobalBounds().height / 2);
		m_wallLives.setPosition(SCREEN_WIDTH / 2, 460.0f);
	}


}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();
	
	//game modes
	if (gameMode == INSTRUCTIONS)
	{//instructions
		window.draw(m_instruction);
		m_message.setString("Instructions (press enter to continue)");
		window.draw(m_message);  // write message to the screen
	}
	else if (gameMode == CHOOSE_CHARACTER)
	{//choosing character
		window.draw(m_chooseCharacter);
		m_message.setString("Choose your character ");
		window.draw(m_message);  // write message to the screen
		window.draw(m_sprite);
		window.draw(m_sprite2);
	}
	else if (gameMode == GAME_PLAY)
	{//game play
		window.draw(m_gameplayBackground);
		m_message.setString("Game Play");
		m_playerLives.setString("Lives: " + std::to_string(rat.getLives()));
		window.draw(m_message);  // write message to the screen
		window.draw(m_playerLives);
		if (poison.getShooting())
		{
			window.draw(poison.getSprite());
		}
		std::cout << rat.getAlive() << std::endl;
		if (rat.getAlive())
		{
			window.draw(rat.getSprite());
		}
		else //player is dead
		{
			gameMode = CLOSING_SCREEN; //switch game mode
		}
		window.draw(cheese.getSprite());
		drawWalls();
		drawGuards();
		window.draw(cat.getSprite());
	}
	else if (gameMode == CLOSING_SCREEN)
	{//closing screen
		window.draw(m_endScreen);
		window.draw(m_closingMessage);
		window.draw(m_restartButton);
		window.draw(m_playerLives);
		window.draw(m_wallLives);
	}

	window.display();
}

void Game::setupText()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	m_playerLives.setFont(m_font);
	m_playerLives.setCharacterSize(24); // set the text size
	m_playerLives.setFillColor(sf::Color::White); // set the text colour
	m_playerLives.setOrigin(0, 0);
	m_playerLives.setPosition(300, 10);  // its position on the screen

	m_closingMessage.setFont(m_font);
	m_closingMessage.setCharacterSize(70);
	m_closingMessage.setFillColor(sf::Color::White);
	m_closingMessage.setPosition(SCREEN_WIDTH / 2, 100);

	m_wallLives.setFont(m_font);
	m_wallLives.setCharacterSize(40);
	m_wallLives.setFillColor(sf::Color::White);
}

void Game::setupBackground()
{
	if (!m_instructionTexture.loadFromFile("ASSETS/IMAGES/instructions.png"))
	{
		std::cout << "error with image file";
	}
	m_instruction.setTexture(m_instructionTexture);
	
	if (!m_chooseCharacterTexture.loadFromFile("ASSETS/IMAGES/clouds.png"))
	{
		std::cout << "error with image file";
	}
	m_chooseCharacter.setTexture(m_chooseCharacterTexture);

	if (!m_gameplayTexture.loadFromFile("ASSETS/IMAGES/background.png"))
	{
		std::cout << "error with image file";
	}
	m_gameplayBackground.setTexture(m_gameplayTexture);

	if (!m_endScreenTexture.loadFromFile("ASSETS/IMAGES/background stars.png"))
	{
		std::cout << "error with image file";
	}
	m_endScreen.setTexture(m_endScreenTexture);

	if (!m_restartTexture.loadFromFile("ASSETS/IMAGES/restart_button.png"))
	{
		std::cout << "error with image file";
	}
	m_restartButton.setTexture(m_restartTexture);

	if (!m_spriteTexture.loadFromFile("ASSETS/IMAGES/mouse.png"))
	{
		std::cout << "error with image file";
	}
	m_sprite.setTexture(m_spriteTexture);
	m_sprite.setTextureRect(sf::IntRect(0, 128, 48, 64));//front facing
	m_sprite.setPosition(500,SCREEN_HEIGHT/2.0f);
	m_sprite.setOrigin(CHARACTER_WIDTH / 2.0f, CHARACTER_HEIGHT / 2.0f);
	m_sprite.setScale(4.0f, 4.0f);
	m_sprite2.setTexture(m_spriteTexture);
	m_sprite2.setTextureRect(sf::IntRect(0, 128, 48, 64));//front facing
	m_sprite2.setPosition(900, SCREEN_HEIGHT/2.0f);
	m_sprite2.setOrigin(CHARACTER_WIDTH / 2.0f, CHARACTER_HEIGHT / 2.0f);
	m_sprite2.setScale(4.0f, 4.0f);
	m_sprite2.setColor(sf::Color::Magenta);
}

void Game::setupWalls()
{
	for (int i = 0; i < MAX_WALLS; i++)
	{
		walls[i].setupWall(i);
	}
}

void Game::drawWalls()
{
	for (int i = 0; i < MAX_WALLS; i++)
	{
		if (walls[i].getAlive())
		{
			window.draw(walls[i].getBody());
		}
		window.draw(walls[i].getMessage());
	}
}

void Game::setupGuards()
{
	for (int i = 0; i < MAX_GUARDS; i++)
	{
		guards[i].setupGuard(i);
	}
}

void Game::drawGuards()
{
	for (int i = 0; i < MAX_GUARDS; i++)
	{
		window.draw(guards[i].getSprite());
	}
}

void Game::moveGuards()
{
	for (int i = 0; i < MAX_GUARDS; i++)
	{
		guards[i].moveGurad();
		guards[i].animate();
	}
}

void Game::processMouseButton(sf::Event t_event)
{
	if (gameMode == CHOOSE_CHARACTER)
	{
		if (sf::Event::MouseButtonReleased == t_event.type)
		{
			sf::Vector2f mousePosition = { static_cast<float>(t_event.mouseButton.x), static_cast<float>(t_event.mouseButton.y) };
			if (m_sprite.getGlobalBounds().contains(mousePosition))
			{
				rat.chooseCharacter(1);
				gameMode = GAME_PLAY;
			}
			else if (m_sprite2.getGlobalBounds().contains(mousePosition))
			{
				rat.chooseCharacter(2);
				gameMode = GAME_PLAY;
			}
		}
	}
	else if (gameMode == CLOSING_SCREEN)
	{
		if (sf::Event::MouseButtonReleased == t_event.type)
		{
			sf::Vector2f mousePosition = { static_cast<float>(t_event.mouseButton.x), static_cast<float>(t_event.mouseButton.y) };
			if (button.getGlobalBounds().contains(mousePosition))
			{
				gameMode = INSTRUCTIONS;
				rat.reset();
				cat.reset(rat);
				setupWalls();
				setupGuards();
				setupText();
				poison.setShooting();
			}
		}
	}
}
