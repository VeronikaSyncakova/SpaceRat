#include "Wall.h" 

void Wall::setupWall(int t_type)
{
	m_lives = 9;
	m_alive = true;
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	m_message.setFont(m_font);
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	
	m_type = t_type+1;
	m_body.setFillColor(sf::Color::White);

	//position of walls
	if (m_type == WEST)
	{
		m_size = { 20.0f, 110.0f };
		m_position = { 690.0f, 400.0f };
		m_message.setPosition(400, 10);  // its position on the screen
		m_message.setString("West: " + std::to_string(m_lives));
	}
	else if (m_type == EAST)
	{
		m_size = { 20.0f, 110.0f };
		m_position = { 810.0f, 400.0f };
		m_message.setPosition(500, 10);  // its position on the screen
		m_message.setString("East: " + std::to_string(m_lives));
	}
	else if(m_type==NORTH)
	{
		m_size = { 110.0f, 20.0f };
		m_position = { 750.0f, 340.0f };
		m_message.setPosition(600, 10);  // its position on the screen
		m_message.setString("North: " + std::to_string(m_lives));
	}
	else if (m_type == SOUTH)
	{
		m_size = { 110.0f, 20.0f };
		m_position = { 750.0f, 460.0f };
		m_message.setPosition(700, 10);  // its position on the screen
		m_message.setString("South: " + std::to_string(m_lives));
	}
	m_body.setSize(m_size);
	m_body.setPosition(m_position);
	m_body.setOrigin(m_size.x / 2, m_size.y / 2);
	
}

sf::RectangleShape Wall::getBody()
{
	return m_body;
}
int Wall::getType()
{
	return m_type;
}

void Wall::decreaseLives()
{
	if (m_lives > 0)
	{
		m_lives--;
	}

	if (m_type == WEST)
	{
		m_message.setString("West: " + std::to_string(m_lives));
	}
	else if (m_type == EAST)
	{
		m_message.setString("East: " + std::to_string(m_lives));
	}
	else if (m_type == NORTH)
	{
		m_message.setString("North: " + std::to_string(m_lives));
	}
	else if (m_type == SOUTH)
	{
		m_message.setString("South: " + std::to_string(m_lives));
	}
	
	if (m_lives == 0) //destroyed wall
	{
		m_alive = false;
		m_position = sf::Vector2f{ -200,-200 }; //off screen
		m_body.setPosition(m_position);
	}
}

bool Wall::getAlive()
{
	return m_alive;
}

sf::Text Wall::getMessage()
{
	return m_message;
}