#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Math.h"

namespace ApplesGame
{

	struct Player
	{
		Position2D position;
		float speed = INITIAL_SPEED;
		Direction direction = Direction::Right;
		sf::Sprite sprite;
	};

	struct Game;

	void InitPlayer(Player& player, const Game& game);
	void DrawPlayer(Player& plater, sf::RenderWindow& window);
	void SetPlayerDirection(Player& player, Direction direction);
	void SetPlayerPosition(Player& player, float deltaTime);
}
