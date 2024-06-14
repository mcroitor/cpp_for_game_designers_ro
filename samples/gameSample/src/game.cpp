#include "game.hpp"
#include "defines.hpp"
#include "tui.hpp"

#include <fstream>
#include <algorithm>
#include <iterator>

Game::Game()
{
}

void Game::Init(const std::string &stage)
{
    std::ifstream fin(stage);
    std::vector<std::string> data;
    std::copy(
        std::istream_iterator<std::string>(fin),
        std::istream_iterator<std::string>(),
        std::back_inserter(data));

    // detect hero
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < data[i].size(); ++j)
        {
            if (data[i][j] == (char)GraphicObject::HERO)
            {
                hero = Hero("Fat Frumos", {i, j});
                data[i][j] = (char)GraphicObject::EMPTY;
                break;
            }
        }
    }

    // detect monsters
    for (size_t i = 0; i < data.size(); ++i)
    {
        for (size_t j = 0; j < data[i].size(); ++j)
        {
            if (data[i][j] == (char)GraphicObject::MONSTER)
            {
                size_t index = monsters.size() + 1;
                monsters.push_back(Monster("Monster " + std::to_string(index), {i, j}));
                data[i][j] = (char)GraphicObject::EMPTY;
            }
        }
    }
    map.Load(data);
}

void Game::Run()
{
    // TODO: implement this
    Point panelPosition = {0, map.GetHeight() + 5};
    Point testPos;
    Direction direction;
    TUI::ClearScreen();
    TUI::Draw(this->Data());

    int cmd;
    // while((cmd = scanKeys()) != VK_ESCAPE) {
    while (true)
    {
        cmd = TUI::ScanKeys();
        // dispatch
        switch (cmd)
        {
        case VK_ESCAPE:
            return;
        case VK_UP:
        case VK_DOWN:
        case VK_LEFT:
        case VK_RIGHT:
            direction = (Direction)cmd;
            testPos = hero.PositionToMove(direction);
            if (map.IsWall(testPos) == false)
            {
                hero.Move(direction);

                TUI::Draw(this->Data());
                TUI::Clear(panelPosition, 40);
                TUI::Write(panelPosition, "Moved to " + ToString(direction));
            }
            else
            {
                TUI::Clear(panelPosition, 40);
                TUI::Write(panelPosition, "Oops! Wall!");
            }
            break;
        case VK_NONAME:
            break;
        default:
            TUI::Clear(panelPosition, 40);
            TUI::Write(panelPosition, "Unknown command");
        }
        Sleep(50);
    }
}

const std::vector<std::string> Game::Data() const
{
    auto data = map.Data();
    data[hero.Position().x][hero.Position().y] = (char)GraphicObject::HERO;
    for (const auto &monster : monsters)
    {
        data[monster.Position().x][monster.Position().y] = (char)GraphicObject::MONSTER;
    }

    return data;
}