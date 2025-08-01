#pragma once
#include "SFML/Audio.hpp"

namespace ApplesGame
{
	struct Audio
	{
		sf::Sound eat;
		sf::Sound win;
		sf::Sound death;
		sf::Sound intro;
		sf::Sound pause;
	};

	struct Game;

	void InitSound(Audio& sound, const Game& game);
	void PlaySound(sf::Sound& sound);
	void StopSound(sf::Sound& sound);
}
