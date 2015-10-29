#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

int main()
{
	//-- We create the render window --//
	//-- The sf::Style::Close argument prevents it from being resized --//
	sf::RenderWindow window(sf::VideoMode(500, 500), "Sprite Test", sf::Style::Close);
	window.setFramerateLimit(60);

	sf::Texture myTexture;

	//-- Load Textures --//
	if (!myTexture.loadFromFile("Ship.png"))
	{}
	else
	{ cout << "Loaded the texture for 'Space Ship'" << endl; }

	
	//-- Create the sprite and set its texture along with its position --//
	sf::Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setPosition(100,100);

	//-- Main game loop --//
	while (window.isOpen())
	{

		//-- The code below checks for user bound events such as keyboard, UI, mouse and joystick events --//
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//-- This Method gets the mouse position --//
		sf::Vector2i mouse = sf::Mouse::getPosition(window);

		//-- This code hides the console window, MS-WINDOWS specific --//
		//HWND hWnd = GetConsoleWindow();
		//ShowWindow( hWnd, SW_HIDE ); 


		//-- Clear and draw methods --//

		window.clear(sf::Color::Black);

		//-- Draw the sprite --//
		window.draw(mySprite);

		window.display();

	}

	return 0;
}