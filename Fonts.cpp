#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

//-- This program is a simple demonstration of Font Rendering using the SFML library --//
//-- Software Created by MossFrog --//

int main()
{
	//-- We create the render window --//
	//-- The sf::Style::Close argument prevents it from being resized --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Font Test", sf::Style::Close);
	window.setFramerateLimit(60);



	//-- Declaring and loading the font into the software --//
	sf::Font myFont;

	if (!myFont.loadFromFile("Pixel Emulator.ttf"))
	{}
	else
	{ cout << "Loaded 'Pixel Emulator.ttf'" << endl; }

	//-- Declaring the sf::Text object to draw on the screen --//
	sf::Text myText;
	//-- Set the font to the font we loaded --//
	myText.setFont(myFont);
	//-- Make it 1.5 times the size --//
	//-- Note that scaling the font itself is better than scaling the text object since it will be less blurry --//
	myText.setScale(1.5,1.5);
	//-- Change its color --//
	myText.setColor(sf::Color::White);
	//-- Set its text to a string --//
	myText.setString("//-- Fonts Test --//");
	//-- Change its position --//
	myText.setPosition(50,50);

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
	
		//-- Draw the font here --//
		window.draw(myText);

        window.display();
		
    }

    return 0;
}