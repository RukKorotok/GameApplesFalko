#pragma once

#include <string>
#include "SFML/Graphics.hpp"

namespace ApplesGame
{	
	// Resources path
	const std::string RESOURCES_PATH = "Resources/";

	// Titles
	const std::string SCORE_TITLE = "Apples collected: ";
	const std::string GAME_OVER_TITLE = "Press: <Y> for restart <N> for Exit";
	const std::string PAUSE_TITLE = "PAUSE";
	const std::string TIME_TITLE = "Time in game: ";
	const std::string HELP_TITLE = "For change direction press: <Up>, <Down>, <Left>, <Right>. For pause press <Space>";
	const std::string UP_APPLE_TITLE = " + Apples [Up]";
	const std::string DOWN_APPLE_TITLE = " - Apples [Down]";
	const std::string START_TITLE = "START [ENTER]";
	const std::string EAT_ALL_TITLE = "Eat All Mode [E]";
	const std::string SPEED_UP_TITLE = "Speed UP [S]";
	const std::string ROCKS_SPAWN_TITLE = "Rocks SPAWN [R]";
	const std::string X_BUTTON_TITLE = "X-3 HARD [H]";
	const std::string APPLES_TITLE = "Apples: ";
	
	// Game config
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f; // Pixels per second
	const float PLAYER_SIZE = 20.f;
	const float ACCELERATION = 20.f; // Pixels per second
	const float APPLE_SIZE = 20.f;
	const float ROCK_SIZE = 30.f;
	const int TEXT_SIZE = 24;

	// Inputs config
	const sf::Keyboard::Key UP_DIRECTION = sf::Keyboard::Key::Up;
	const sf::Keyboard::Key DOWN_DIRECTION = sf::Keyboard::Key::Down;
	const sf::Keyboard::Key LEFT_DIRECTION = sf::Keyboard::Key::Left;
	const sf::Keyboard::Key RIGHT_DIRECTION = sf::Keyboard::Key::Right;
	const sf::Keyboard::Key PAUSE = sf::Keyboard::Key::Space;
	const sf::Keyboard::Key START = sf::Keyboard::Key::Enter;
	const sf::Keyboard::Key EXIT = sf::Keyboard::Key::Escape;
	const sf::Keyboard::Key EAT_ALL_MODE = sf::Keyboard::Key::E;
	const sf::Keyboard::Key SPEED_UP_MODE = sf::Keyboard::Key::S;
	const sf::Keyboard::Key ROCKS_UP_MODE = sf::Keyboard::Key::R;
	const sf::Keyboard::Key HARD_MODE = sf::Keyboard::Key::H;
	const sf::Keyboard::Key YES = sf::Keyboard::Key::Y;
	const sf::Keyboard::Key NO = sf::Keyboard::Key::N;
}
