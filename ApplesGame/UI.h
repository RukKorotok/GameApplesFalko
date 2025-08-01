#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Math.h"

namespace ApplesGame
{
	const float BUTTON_WIDTH = 170.0f;
	const float BUTTON_HEIGHT = 30.0f;

	struct UI
	{
		Position2D position;
		Direction direction = Direction::Right;
		sf::Sprite mainMenuSprite;
		sf::Sprite gameOverSprite;
		sf::Sprite winSprite;
		sf::Text gameText;
		sf::Text timeInGameText;
		sf::Text gameOverText;
		sf::Text pauseText;
		sf::Text helpText;
		sf::Text upAppleText;
		sf::Text downAppleText;
		sf::Text startText;
		sf::Text eatAllText;
		sf::Text speedUpText;
		sf::Text rocksSpawnText;
		sf::Text xText;
		sf::Text applesInGame;
		sf::RectangleShape upAppleButton;
		sf::RectangleShape downAppleButton;
		sf::RectangleShape startButton;
		sf::RectangleShape eatAllButton;
		sf::RectangleShape speedUpButton;
		sf::RectangleShape rocksSpawnButton;
		sf::RectangleShape xButton;
	};

	struct Game;

	void InitSprite(sf::Sprite& sprite, const sf::Texture& texture, float heightMulty, float widthMulty);
	void InitButton(sf::RectangleShape& button, const sf::Color& color, float heightMulty, float widthMulty);
	void InitText(sf::Text& text, const sf::Font& font, const std::string title, const sf::Color& color, const float height, const float width);

	void InitUI(UI& ui, const Game& game);
	void DrawMainMenu(UI& ui, sf::RenderWindow& window);
	void DrawPause(UI& ui, sf::RenderWindow& window);
	void DrawGameOver(UI& ui, sf::RenderWindow& window);
	void DrawWin(UI& ui, sf::RenderWindow& window);
	void DrawGameUI(Game& game, sf::RenderWindow& window);

	void SetStringInText(sf::Text& text, std::string string);
	void SetButtonColor(sf::RectangleShape& button, const sf::Color& color);
	void SetTextColor(sf::Text& text, const sf::Color& color);
}
