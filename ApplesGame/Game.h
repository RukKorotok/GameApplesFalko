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
		ExitGame,
		Win
	};

	enum class GameMode
	{
		SpeedUp = 1 << 0,
		RocksUp = 1 << 1,
		HardCore = 1 << 2,
		EatAll = 1 << 3,
	};

	struct Game
	{
		// Game objects
		UI ui;
		Player player;
		int rocksInField = 0;
		int applesInField = 0;
		int applesInGame = 10;
		std::unique_ptr<Apple[]> apples;
		std::unique_ptr<Rock[]> rocks;

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
		sf::Texture winTexture;
		sf::SoundBuffer eatAppleWave;
		sf::SoundBuffer winWave;
		sf::SoundBuffer deathWave;
		sf::SoundBuffer introWave;
		sf::SoundBuffer pauseWave;
		Audio audio;
	};

	void InitGame(Game& game);
	void StartGame(Game& game);
	void GameOver(Game& game);
	void Win(Game& game);
	void ExitFromGame(sf::RenderWindow& window);
	void EatApple(Game& game, int appleNumber);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ChangeGameMode(Game& game, GameMode gameMode);
}
