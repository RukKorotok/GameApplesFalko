#pragma once

namespace ApplesGame
{
	struct Game;

	void HandleInputDirection(Game& game);
	void HandleInputOnGameStoped(Game& game);
	bool HandlerInputMainMenu(Game& game, bool isAllKeysRealised);
	bool HandlerInputPause(Game& game, bool isAllKeysRealised);
}
