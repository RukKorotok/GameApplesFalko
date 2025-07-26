#include "UI.h"
#include "Game.h"

namespace ApplesGame
{
	//-----------------------------------------------------------------------------------------------------------
	void InitSprite(sf::Sprite& sprite, const sf::Texture& texture, float heightMulty, float widthMulty)
	{
		float mainMenueSpriteSize = SCREEN_HEIGHT * 0.9f;
		float textXIndentation = SCREEN_WIDTH - 400.0f;

		sprite.setTexture(texture);
		SetSpriteSize(sprite, mainMenueSpriteSize, mainMenueSpriteSize);
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
		sprite.setPosition(SCREEN_HEIGHT * heightMulty, SCREEN_WIDTH * widthMulty);
	}
	//-----------------------------------------------------------------------------------------------------------
	void InitButton(sf::RectangleShape& button, const sf::Color& color, float heightMulty, float widthMulty)
	{
		button.setSize({ BUTTON_WIDTH, BUTTON_HEIGHT });
		button.setPosition(SCREEN_HEIGHT * heightMulty, SCREEN_WIDTH * widthMulty);
		button.setFillColor(color);
	}
	//-----------------------------------------------------------------------------------------------------------
	void InitText(sf::Text& text, const sf::Font& font, const std::string title, const sf::Color& color, const float heigh, const float width)
	{
		text.setFont(font);
		text.setCharacterSize(TEXT_SIZE - 5);
		text.setString(title);
		text.setFillColor(color);
		text.setPosition(heigh, width);
	}
	//-----------------------------------------------------------------------------------------------------------
	void InitUI(UI& ui, const Game& game)
	{
		float mainMenueSpriteSize = SCREEN_HEIGHT * 0.9f;
		float textXIndentation = SCREEN_WIDTH - 400.0f;

		// Init UI sprites
		InitSprite(ui.mainMenuSprite, game.mainMenueTexture, 0.38f, 0.35f);
		InitSprite(ui.gameOverSprite, game.gameOverTexture, 0.75f, 0.35f);

		// Init UI shapes
		InitButton(ui.upAppleButton, sf::Color::Green, 0.7f, 0.2f);
		InitButton(ui.downAppleButton, sf::Color::Red, 0.7f, 0.35f);
		InitButton(ui.startButton, sf::Color::Red, 0.7f, 0.4f);
		InitButton(ui.speedUpButton, sf::Color::Green, 1.0f, 0.2f);
		InitButton(ui.rocksSpawnButton, sf::Color::Green, 1.0f, 0.3f);
		InitButton(ui.xButton, sf::Color::Red, 1.0f, 0.4f);

		// Init UI text
		InitText(ui.gameText, game.font, SCORE_TITLE, sf::Color::Yellow, SCREEN_WIDTH - 250.0f, 5.0f);
		InitText(ui.gameOverText, game.font, GAME_OVER_TITLE, sf::Color::Red, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT - 50.0f);
		InitText(ui.pauseText, game.font, PAUSE_TITLE, sf::Color::Red, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		InitText(ui.helpText, game.font, HELP_TITLE, sf::Color::Yellow, 0.0f, SCREEN_HEIGHT - 25.0f);
		InitText(ui.upAppleText, game.font, UP_APPLE_TITLE, sf::Color::White, SCREEN_HEIGHT * 0.7f, SCREEN_WIDTH * 0.2f);
		InitText(ui.downAppleText, game.font, DOWN_APPLE_TITLE, sf::Color::White, SCREEN_HEIGHT * 0.7f, SCREEN_WIDTH * 0.35f);
		InitText(ui.startText, game.font, START_TITLE, sf::Color::White, SCREEN_HEIGHT * 0.7f, SCREEN_WIDTH * 0.4f);
		InitText(ui.speedUpText, game.font, SPEED_UP_TITLE, sf::Color::White, SCREEN_HEIGHT * 1.0f, SCREEN_WIDTH * 0.2f);
		InitText(ui.rocksSpawnText, game.font, ROCKS_SPAWN_TITLE, sf::Color::White, SCREEN_HEIGHT * 1.0f, SCREEN_WIDTH * 0.3f);
		InitText(ui.xText, game.font, X_BUTTON_TITLE, sf::Color::White, SCREEN_HEIGHT * 1.0f, SCREEN_WIDTH * 0.4f);
		InitText(ui.applesInGame, game.font, APPLES_TITLE + std::to_string(game.applesInGame), sf::Color::Green, SCREEN_HEIGHT * 0.7f, SCREEN_WIDTH * 0.28f);
	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawMainMenu(UI& ui, sf::RenderWindow& window)
	{
		window.clear();
		window.draw(ui.mainMenuSprite);
		window.draw(ui.upAppleButton);
		window.draw(ui.upAppleText);
		window.draw(ui.downAppleButton);
		window.draw(ui.downAppleText);
		window.draw(ui.startButton);
		window.draw(ui.startText);
		window.draw(ui.speedUpButton);
		window.draw(ui.speedUpText);
		window.draw(ui.rocksSpawnButton);
		window.draw(ui.rocksSpawnText);
		window.draw(ui.xButton);
		window.draw(ui.xText);
		window.draw(ui.applesInGame);
		window.display();
	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawPause(UI& ui, sf::RenderWindow& window)
	{
		window.draw(ui.pauseText);
		window.display();
	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawGameOver(UI& ui, sf::RenderWindow& window)
	{
		window.clear();
		window.draw(ui.gameText);
		window.draw(ui.gameOverSprite);
		window.draw(ui.gameOverText);
		window.display();
	}
	//-----------------------------------------------------------------------------------------------------------
	void DrawGameUI(Game& game, sf::RenderWindow& window)
	{
		game.ui.gameText.setString(SCORE_TITLE + std::to_string(game.numEatenApples));
		window.draw(game.ui.gameText);
		window.draw(game.ui.helpText);
	}
	//-----------------------------------------------------------------------------------------------------------
	void SetStringInText(sf::Text& text, std::string string)
	{
		text.setString(string);
	}
	//-----------------------------------------------------------------------------------------------------------
	void SetButtonColor(sf::RectangleShape& button, const sf::Color& color)
	{
		button.setFillColor(color);
	}
	//-----------------------------------------------------------------------------------------------------------
	void SetTextColor(sf::Text& text, const sf::Color& color)
	{
		text.setFillColor(color);
	}
}
