#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>


//-- This program is a simple demonstration of periodic key inputs in SFML --//
//-- KeyPress and KeyRelease Actions Are demonstrated --//
int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Keyboard Test - 2", sf::Style::Close);
	window.setFramerateLimit(60);

	//-- We set the keyRepeat to false thus enabling incremented on press actions --//
	window.setKeyRepeatEnabled(false);

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

			//-- Single stroke keyPress Event --//
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					pawnY = pawnY - 40;
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					pawnY = pawnY + 40;
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					pawnX = pawnX - 40;
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					pawnX = pawnX + 40;
				}

				pawn.setFillColor(sf::Color::Cyan);
			}


			//-- A simple color change to indicate that the key was relased. --//

			if (event.type == sf::Event::KeyReleased)
			{
				pawn.setFillColor(sf::Color::Red);
			}
		}

		sf::Vector2i mouse = sf::Mouse::getPosition(window);
	

		pawn.setPosition(pawnX,pawnY);

		//-- This code hides the console window, MS-WINDOWS specific --//
		HWND hWnd = GetConsoleWindow();
		//ShowWindow( hWnd, SW_HIDE ); 


		//-- Clear and draw methods --//
		window.clear(sf::Color::Black);

		window.draw(pawn);

		window.display();

	}

	return 0;
}