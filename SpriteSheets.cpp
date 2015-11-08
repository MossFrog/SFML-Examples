#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

using namespace std;

int main()
{
	//-- We create the render window --//
	//-- The sf::Style::Close argument prevents it from being resized --//
	sf::RenderWindow window(sf::VideoMode(500, 500), "SpriteSheet Test", sf::Style::Close);
	window.setFramerateLimit(120);

	sf::Texture myTexture;

	//-- Load Textures --//
	if (!myTexture.loadFromFile("Fireball_3.png"))
	{}
	else
	{ cout << "Loaded the texture for 'Fire Ball'" << endl; }

	//-- Define the Sprite and the SpriteCounter to cycle through the spritesheet --//
	//-- We use the setTextureRect method to modify the chunk we use from the spritesheet --//
	int spriteCounter = 0;

	sf::Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setTextureRect(sf::IntRect(spriteCounter,0,64,64));
	mySprite.setPosition(100,100);

	//-- Define a clock for the animation --//
	sf::Clock spriteClock;
	spriteClock.restart();


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


		//-- If the time is over 150ms change the frame --//
		if(spriteClock.getElapsedTime() >= sf::milliseconds(150))
		{
			//-- Increment the counter by the offset --//
			spriteCounter += 64;
			//-- Make sure we do not overflow the bounds of the spritesheet --//
			if(spriteCounter > 156)
			{
				spriteCounter = 0;
			}

			//-- Update the texture rectangle for mySprite --//
			mySprite.setTextureRect(sf::IntRect(spriteCounter,0,64,64));

			//-- Restart the clock to wait for the next second --//
			spriteClock.restart();
		}


		//-- Clear and draw methods --//

		window.clear(sf::Color::Black);

		//-- Draw the updated sprite --//
		window.draw(mySprite);

		window.display();

	}

	return 0;
}