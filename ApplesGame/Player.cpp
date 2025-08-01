#include "Player.h"
#include "Game.h"

namespace ApplesGame
{

	//-----------------------------------------------------------------------------------------------------------
	void InitPlayer(Player& player, const Game& game)
	{
		// Init player state
		player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = Direction::Right;

		// Init player sprite
		player.sprite.setTexture(game.playerTexture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
		player.sprite.setRotation(0.0f);

	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.position.x, player.position.y);
		window.draw(player.sprite);
	}
	// ----------------------------------------------------------------------------------------------------------
	void SetPlayerDirection(Player& player, Direction direction)
	{
		player.direction = direction;

		if (direction == Direction::Left)
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, -PLAYER_SIZE);
		}
		else
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		}

		switch (direction)
		{
		case Direction::Right:
		{
			player.sprite.setRotation(0.0f);

			break;
		}
		case Direction::Up:
		{
			player.sprite.setRotation(-90.0f);

			break;
		}
		case Direction::Left:
		{
			player.sprite.setRotation(180.0f);

			break;
		}
		case Direction::Down:
		{
			player.sprite.setRotation(90.0f);

			break;
		}
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	void SetPlayerPosition(Player& player, float deltaTime)
	{
		switch (player.direction)
		{
		case Direction::Right:
		{
			player.position.x += player.speed * deltaTime;

			break;
		}
		case Direction::Up:
		{
			player.position.y -= player.speed * deltaTime;

			break;
		}
		case Direction::Left:
		{
			player.position.x -= player.speed * deltaTime;

			break;
		}
		case Direction::Down:
		{
			player.position.y += player.speed * deltaTime;

			break;
		}
		}
	}
}
