#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"
#include "Game.h"
#include <memory>

//-----------------------------------------------------------------------------------------------------------
int main()
{
	using namespace ApplesGame;

	bool isKeysPressed = false;
	sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;
	State currentState = State::Undefined;
	int seed = (int)time(nullptr);
	srand(seed);
	sf::Event event;

	// Init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

	// Game initialization
	Game game;
	InitGame(game);
	InitUI(game.ui, game);
	InitSound(game.audio, game);
	
	// Init game clocks
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// Main loop
	while (window.isOpen())
	{
		// Reduce framerate to not spam CPU and GPU
		sf::sleep(sf::milliseconds(16));

		// Calculate time delta
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		// Read events
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
			{
				window.close();
				break;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				pressedKey = event.key.code;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == pressedKey)
			{
				isKeysPressed = false;

			}
		}

		// Check game states
		switch (game.state)
		{
		case State::MainMenu:
		{
			if (currentState != game.state)
			{
				DrawMainMenu(game.ui, window);
				PlaySound(game.audio.intro);
				currentState = game.state;
			}
			if (HandlerInputMainMenu(game, isKeysPressed))
			{
				DrawMainMenu(game.ui, window);
				isKeysPressed = true;
			}

			break;
		}
		case State::InProgress:
		{
			currentState = game.state;
			HandleInputDirection(game);
			SetPlayerPosition(game.player, deltaTime);
			UpdateGame(game, deltaTime);
			DrawGame(game, window);

			if (HandlerInputPause(game, isKeysPressed) )
			{
				isKeysPressed = true;
			}
			break;
		}
		case State::Paused:
		{
			if (currentState != game.state)
			{
				DrawPause(game.ui, window);
				PlaySound(game.audio.pause);
				currentState = game.state;
			}
 			if (HandlerInputPause(game, isKeysPressed) )
			{
				isKeysPressed = true;
			}
			break;
		}
		case State::GameOver:
		{
			if (currentState != game.state)
			{
				DrawGameOver(game.ui, window);
				PlaySound(game.audio.death);
				currentState = game.state;
			}
			GameOver(game);
			HandleInputOnGameStoped(game);
			break;
		}
		case State::Win:
		{
			if (currentState != game.state)
			{
				DrawWin(game.ui, window);
				PlaySound(game.audio.win);
				currentState = game.state;
			}
			Win(game);
			HandleInputOnGameStoped(game);
			break;
		}
		case State::ExitGame:
		{
			ExitFromGame(window);
			break;
		}
		}
	}
	return 0;
}
