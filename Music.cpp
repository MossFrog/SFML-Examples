#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

//-- This program is a simple demonstration of Music using the SFML library --//
//-- Software Created by MossFrog --//

int main()
{
	//-- We create the render window --//
	//-- The sf::Style::Close argument prevents it from being resized --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Music Test", sf::Style::Close);
	window.setFramerateLimit(60);


	//-- The music file is not loaded it is merely opened from its actual source --//
	sf::Music mainMusic;

	if (!mainMusic.openFromFile("chords.ogg"))
	{}
	else
	{ cout << "Loaded 'chords.ogg'" << endl; }

	//-- We start playing the music infinitely , do not put this method in the main game loop (or else it will restart 60 times a second --//
	mainMusic.setLoop(true);
	mainMusic.play();

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
	
		

        window.display();
		
    }

    return 0;
}