#include <SFML/Graphics.hpp>
#include "figure.h"
#include "game.h"
#include "clear.h"
#include "field.h"

using namespace sf;

const std::string GAME_TITLE = "Tetris";
const int SPRITE_SIZE = 18;

/**
 * @brief Draw tetris shape
 * 
 * @param window
 * @param sprite
 */
void DrawShape(Window &window, Sprite &sprite)
{
    for (int i = 0; i < 4; i++)
    {
        sprite.setTextureRect(
            IntRect(
                colorNum * SPRITE_SIZE,
                0,
                SPRITE_SIZE,
                SPRITE_SIZE));
        sprite.setPosition(a[i].x * SPRITE_SIZE, a[i].y * SPRITE_SIZE);
        window.draw(sprite);
    }
}

/**
 * @brief Draw tetris field
 * 
 * @param window
 * @param sprite
 */
void DrawField(Window &window, Sprite &sprite)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (field[i][j] == 0)
            {
                continue;
            }
            sprite.setTextureRect(
                IntRect(
                    field[i][j] * SPRITE_SIZE,
                    0,
                    SPRITE_SIZE,
                    SPRITE_SIZE));
            sprite.setPosition(j * SPRITE_SIZE, i * SPRITE_SIZE);
            window.draw(sprite);
        }
    }
}

int main()
{
    RenderWindow window(VideoMode(320, 480), GAME_TITLE);

    Texture texture;
    texture.loadFromFile("images/tiles.png");
    Sprite sprite(texture);

    int dx = 0;
    bool rotate = false;
    float timer = 0, delay = 0.3;
    Clock clock;
    int colorNum = 1;

    generateNewFigure();

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        handleInput(window, dx, rotate);
        updateGameState(window, dx, rotate, timer, delay, colorNum);

        clearFullLines();

        window.clear(Color::White);

        DrawField(window, sprite);
        DrawShape(window, sprite);

        window.display();
    }

    return 0;
}