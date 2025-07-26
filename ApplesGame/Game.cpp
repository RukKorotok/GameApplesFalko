#include "Game.h"
#include <cassert>
#include <bitset>


namespace ApplesGame
{
	//-----------------------------------------------------------------------------------------------------------
	void InitGame(Game& game)
	{
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png") );
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\gameApple.png") );
		assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.mainMenueTexture.loadFromFile(RESOURCES_PATH + "\\menuApple.png") );
		assert(game.gameOverTexture.loadFromFile(RESOURCES_PATH + "\\gameOver.png") );
		assert(game.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf") );
		assert(game.eatAppleWave.loadFromFile(RESOURCES_PATH + "AppleEat.wav") );
		assert(game.deathWave.loadFromFile(RESOURCES_PATH + "Death.wav") );
		assert(game.introWave.loadFromFile(RESOURCES_PATH + "Intro.wav") );
		assert(game.pauseWave.loadFromFile(RESOURCES_PATH + "Pause.wav") );

		game.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT) );
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.f, 0.f);
		game.difficulty = 0b000;
		game.applesInGame = 10;
		game.state = State::MainMenu;
	}
	//-----------------------------------------------------------------------------------------------------------
	void StartGame(Game& game)
	{
		game.apples = std::shared_ptr<Apple[]>(new Apple[game.applesInGame]);
		game.rocks = std::shared_ptr<Rock[]>(new Rock[game.rocksInGame]);

		game.numEatenApples = 0;
		game.rocksInGame = 0;
		game.state = State::InProgress;

		InitPlayer(game.player, game);

		for (int i = 0; i < game.applesInGame; ++i)
		{
			InitApple(game.apples[i], game);
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	void GameOver(Game& game)
	{
		game.state = State::GameOver;
	}
	//-----------------------------------------------------------------------------------------------------------
	void ExitFromGame(sf::RenderWindow& window)
	{
		window.close();
	}
	//-----------------------------------------------------------------------------------------------------------
	void EatApple(Game& game, int appleNumber)
	{
		std::shared_ptr<Rock[]> newRocks;
		int addedRocks = 0;

		PlaySound(game.audio.eat);
		game.apples[appleNumber].position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
		++game.numEatenApples;

		//If activated speed mode
		if (game.difficulty & static_cast<uint32_t>(GameMode::SpeedUp) )
		{
			if (game.difficulty & static_cast<uint32_t>(GameMode::HardCore) )
			{
				game.player.speed += ACCELERATION * 3;
			}
			else
			{
				game.player.speed += ACCELERATION;
			}
		}

		//If activated rocks mode
		if (game.difficulty & static_cast<uint32_t>(GameMode::RocksUp) )
		{
			if (game.difficulty & static_cast<uint32_t>(GameMode::HardCore) )
			{
				addedRocks = 3;
			}
			else
			{
				addedRocks = 1;
			}
			// Added rocks in array 
			newRocks = std::shared_ptr<Rock[]>(new Rock[game.rocksInGame + addedRocks]);
			std::copy(game.rocks.get(), game.rocks.get() + game.rocksInGame, newRocks.get() );

			for (int i = 0; i < addedRocks; ++i)
			{
				++game.rocksInGame;
				InitRock(newRocks[game.rocksInGame - 1], game);
			}
			game.rocks = std::move(newRocks);
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	void UpdateGame(Game& game, float deltaTime)
	{

		// Find player collisions with apples
		for (int i = 0; i < game.applesInGame; ++i)
		{
			if (IsCirclesCollide(game.player.position, PLAYER_SIZE / 2.f, game.apples[i].position, APPLE_SIZE / 2.f))
			{
				EatApple(game, i);
			}
		}

		// Find player collisions with rocks
		for (int i = 0; i < game.rocksInGame; ++i)
		{
			if (IsRectanglesCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE },
					game.rocks[i].position, { ROCK_SIZE, ROCK_SIZE }))
			{
				GameOver(game);
			}
		}

		// Check screen borders collision
		if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f || game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH ||
			game.player.position.y - PLAYER_SIZE / 2.f < 0.f || game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
		{
			GameOver(game);
		}

	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.clear();
		window.draw(game.background);
		DrawPlayer(game.player, window);
		for (int i = 0; i < game.applesInGame; ++i)
		{
			DrawApple(game.apples[i], window);
		}
		for (int i = 0; i < game.rocksInGame; ++i)
		{
			DrawRock(game.rocks[i], window);
		}
		DrawGameUI(game, window);
		window.display();
	}
	void ChangeGameMode(Game& game, GameMode gameMode)
	{

		// Set game difficult
		if (game.difficulty & static_cast<uint32_t>(gameMode) )
		{
			game.difficulty &= ~static_cast<uint32_t>(gameMode);
		}
		else
		{
			game.difficulty |= static_cast<uint32_t>(gameMode);
		}

		// Change main menu buttons and text
		if (game.difficulty & static_cast<uint32_t>(GameMode::SpeedUp) )
		{
			SetButtonColor(game.ui.speedUpButton, sf::Color::Yellow);
			SetTextColor(game.ui.speedUpText, sf::Color::Black);
		}
		else
		{
			SetButtonColor(game.ui.speedUpButton, sf::Color::Green);
			SetTextColor(game.ui.speedUpText, sf::Color::White);
		}

		if (game.difficulty & static_cast<uint32_t>(GameMode::RocksUp) )
		{
			SetButtonColor(game.ui.rocksSpawnButton, sf::Color::Yellow);
			SetTextColor(game.ui.rocksSpawnText, sf::Color::Black);
		}
		else
		{
			SetButtonColor(game.ui.rocksSpawnButton, sf::Color::Green);
			SetTextColor(game.ui.rocksSpawnText, sf::Color::White);
		}

		if (game.difficulty & static_cast<uint32_t>(GameMode::HardCore) )
		{
			SetButtonColor(game.ui.xButton, sf::Color::Yellow);
			SetTextColor(game.ui.xText, sf::Color::Black);
		}
		else
		{
			SetButtonColor(game.ui.xButton, sf::Color::Red);
			SetTextColor(game.ui.xText, sf::Color::White);
		}
		
	}
}
