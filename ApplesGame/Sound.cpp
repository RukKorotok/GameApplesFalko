#include "Sound.h"
#include "Game.h"

namespace ApplesGame
{

	//------------------------------------------------------------------------------------------------------------
	void InitSound(Audio& sound, const Game& game)
	{
		sound.eat.setBuffer(game.eatAppleWave);
		sound.win.setBuffer(game.winWave);
		sound.death.setBuffer(game.deathWave);
		sound.intro.setBuffer(game.introWave);
		sound.pause.setBuffer(game.pauseWave);
	}

	//------------------------------------------------------------------------------------------------------------
	void PlaySound(sf::Sound& sound)
	{
		sound.play();
	}

	//-----------------------------------------------------------------------------------------------------------
	void StopSound(sf::Sound& sound)
	{
		sound.stop();
	}
}
