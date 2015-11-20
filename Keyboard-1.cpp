#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>


//-- This program is a simple demonstration of continuous key inputs in SFML --//
int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Keyboard Test", sf::Style::Close);
	window.setFramerateLimit(60);

	//-- Create and place the object at the given specifications --//
	//-- For convenience the object is named "pawn" --//
	sf::RectangleShape pawn;
	pawn.setOrigin(25,25);
	pawn.setPosition(300,300);
	pawn.setSize(sf::Vector2f(50, 50));
	pawn.setFillColor(sf::Color::Cyan);

	//-- Give the object its initial positions --//
	int pawnX = pawn.getPosition().x;
	int pawnY = pawn.getPosition().y;

	while (window.isOpen())
	{

		

		//-- The code below allows the user to manipulate the window --//
		sf::Event event;


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2i mouse = sf::Mouse::getPosition(window);


		//-- Get the keys pressed, these methods will be called perpetually as the main game loop resets --//
		//-- This allows the user to hold down keys for motion --//

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pawnY--;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pawnY++;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pawnX--;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pawnX++;
		}

		pawn.setPosition(pawnX,pawnY);

		//-- This code hides the console window, MS-WINDOWS specific --//
		HWND hWnd = GetConsoleWindow();
		//ShowWindow( hWnd, SW_HIDE ); 

		window.clear(sf::Color::Black);

		window.draw(pawn);

		window.display();

	}

	return 0;
}