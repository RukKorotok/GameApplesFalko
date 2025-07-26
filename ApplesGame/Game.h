#pragma once

#include "SFML/Audio.hpp"
#include "Config.h"
#include "Math.h"
#include "UI.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Sound.h"
#include "InputHandlers.h"
#include <memory>

namespace ApplesGame
{
	enum class State
	{
		Undefined = 0,
		MainMenu,
		InProgress,
		Paused,
		GameOver,
		ExitGame
	};

	enum class GameMode
	{
		SpeedUp = 1 << 0,
		RocksUp = 1 << 1,
		HardCore = 1 << 2,
	};

	struct Game
	{
		// Game objects
		UI ui;
		Player player;
		int rocksInGame = 0;
		int applesInGame = 10;
		std::shared_ptr<Apple[]> apples;
		std::shared_ptr<Rock[]> rocks;

		// Global game data
		int numEatenApples = 0;
		State state = State::MainMenu;
		uint32_t difficulty = 0b111;
		sf::RectangleShape background;

		// Resources
		sf::Font font;
		sf::Texture playerTexture;
		sf::Texture rockTexture;
		sf::Texture appleTexture;
		sf::Texture mainMenueTexture;
		sf::Texture gameOverTexture;
		sf::SoundBuffer eatAppleWave;
		sf::SoundBuffer deathWave;
		sf::SoundBuffer introWave;
		sf::SoundBuffer pauseWave;
		Audio audio;
	};

	void InitGame(Game& game);
	void StartGame(Game& game);
	void GameOver(Game& game);
	void ExitFromGame(sf::RenderWindow& window);
	void EatApple(Game& game, int appleNumber);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ChangeGameMode(Game& game, GameMode gameMode);
}
