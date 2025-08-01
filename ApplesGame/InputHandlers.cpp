#include "InputHandlers.h"
#include "Math.h"
#include "Game.h"

namespace ApplesGame
{
	//------------------------------------------------------------------------------------------------------------
	void HandleInputDirection(Game& game)
	{
		// Change player direction
		if (sf::Keyboard::isKeyPressed(RIGHT_DIRECTION) )
		{
			SetPlayerDirection(game.player, Direction::Right);
		}
		else if (sf::Keyboard::isKeyPressed(UP_DIRECTION) )
		{
			SetPlayerDirection(game.player, Direction::Up);
		}
		else if (sf::Keyboard::isKeyPressed(LEFT_DIRECTION) )
		{
			SetPlayerDirection(game.player, Direction::Left);
		}
		else if (sf::Keyboard::isKeyPressed(DOWN_DIRECTION) )
		{
			SetPlayerDirection(game.player, Direction::Down);
		}
	}
	//------------------------------------------------------------------------------------------------------------
	void HandleInputOnGameStoped(Game& game)
	{
		if (sf::Keyboard::isKeyPressed(YES) )
		{
			game.state = State::MainMenu;
			StopSound(game.audio.death);
			StopSound(game.audio.win);
		}
		else if (sf::Keyboard::isKeyPressed(NO) )
		{
			game.state = State::ExitGame;
		}
	}
	//------------------------------------------------------------------------------------------------------------
	bool HandlerInputMainMenu(Game& game, bool isAllKeysRealised)
	{
		if (!isAllKeysRealised)
		{
			if (sf::Keyboard::isKeyPressed(UP_DIRECTION) )
			{
				++game.applesInGame;
				SetStringInText(game.ui.applesInGame, APPLES_TITLE + std::to_string(game.applesInGame) );

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(DOWN_DIRECTION))
			{
				if (game.applesInGame > 1)
				{
					--game.applesInGame;
					SetStringInText(game.ui.applesInGame, APPLES_TITLE + std::to_string(game.applesInGame) );
				}

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(START) )
			{
				StartGame(game);
				StopSound(game.audio.intro);

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(EAT_ALL_MODE))
			{
				ChangeGameMode(game, GameMode::EatAll);

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(SPEED_UP_MODE) )
			{
				ChangeGameMode(game, GameMode::SpeedUp);

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(ROCKS_UP_MODE) )
			{
				ChangeGameMode(game, GameMode::RocksUp);

				return true;
			}
			else if (sf::Keyboard::isKeyPressed(HARD_MODE) )
			{
				ChangeGameMode(game, GameMode::HardCore);

				return true;
			}
			return false;
		}
		return false;
	}
	//------------------------------------------------------------------------------------------------------------
	bool HandlerInputPause(Game& game, bool isAllKeysRealised)
	{
		if (!isAllKeysRealised && sf::Keyboard::isKeyPressed(PAUSE) )
		{
			switch (game.state)
			{
			case (State::InProgress):
			{
				game.state = State::Paused;

				return true;
			}
			case (State::Paused):
			{
				game.state = State::InProgress;

				return true;
			}
			} 

			return false;
		}
		return false;
	}
}
