#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

//-- This program is a simple demonstration of Audio using the SFML library --//
//-- Software Created by MossFrog --//

//-- Audio Samples Created with BFXR --//

//-- Use the A,S,D keys to test --//
int main()
{
	//-- We create the render window --//
	sf::RenderWindow window(sf::VideoMode(800, 600), "Audio Test", sf::Style::Close);
	window.setFramerateLimit(60);


	//-- Load all the sound files into seperate Buffers --//
	sf::SoundBuffer buffer1;
    if (!buffer1.loadFromFile("Pickup_Coin.wav"))
	{ }
	else
	{ cout << "Successfully loaded 'Pickup_Coin.wav'" << endl; }

	sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("Blip_Select.wav"))
	{ }
	else
	{ cout << "Successfully loaded 'Blip_Select.wav'" << endl; }

	sf::SoundBuffer buffer3;
    if (!buffer3.loadFromFile("Randomize4.wav"))
	{ }
	else
	{ cout << "Successfully loaded 'Randomize4.wav'" << endl; }

	//-- Define the sound --//
	sf::Sound sound;
	
	
	

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
		

		//-- Use the A,S,D keys to chage the buffer and play the sound --//
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sound.setBuffer(buffer1);
			sound.play();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sound.setBuffer(buffer2);
			sound.play();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sound.setBuffer(buffer3);
			sound.play();
		}

		//-- This code hides the console window, MS-WINDOWS specific --//
		//HWND hWnd = GetConsoleWindow();
		//ShowWindow( hWnd, SW_HIDE ); 
		

		//-- Clear and draw methods --//

		window.clear(sf::Color::Black);
	
		

        window.display();
		
    }

    return 0;
}