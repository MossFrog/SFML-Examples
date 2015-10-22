#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>


//-- This program is a simple demonstration of primitive shapes using the SFML library --//
//-- Software Created by MossFrog --//
int main()
{
	//-- We create the render window --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes test", sf::Style::Close);
	window.setFramerateLimit(60);

	//-- Define our shapes and initialize their positions --//

	//-- The variable is defined with its diameter --//
	sf::CircleShape myCircle(35);
	myCircle.setFillColor(sf::Color::Blue);
	myCircle.setPosition(400,400);
	//-- We can give it an outline and set its color --//
	myCircle.setOutlineThickness(10);
	myCircle.setOutlineColor(sf::Color::Red);

	//-- Define and initialize the rectangle --//
	sf::RectangleShape myRect;
	myRect.setPosition(50,50);
	myRect.setSize(sf::Vector2f(100, 100));
	myRect.setFillColor(sf::Color::Cyan);

	//-- Circle shapes can have any number of "edges" --//
	sf::CircleShape myTriangle(45,3);
	myTriangle.setFillColor(sf::Color::White);
	myTriangle.setPosition(700,150);


	sf::CircleShape myOctagon(25,8);
	myOctagon.setFillColor(sf::Color::Magenta);
	myOctagon.setPosition(700,500);

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

		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		

		//-- This code hides the console window, MS-WINDOWS specific --//
		HWND hWnd = GetConsoleWindow();
		ShowWindow( hWnd, SW_HIDE ); 
		

		//-- Clear and draw methods --//

		window.clear(sf::Color::Black);
	
		//-- We do all the drawing after the clear event, if not any drawing we do will not be visible --//
		window.draw(myCircle);
		window.draw(myRect);
		window.draw(myOctagon);
		window.draw(myTriangle);

        window.display();
		
    }

    return 0;
}