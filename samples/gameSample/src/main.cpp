#include "game.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " <stage_desc_file>" << std::endl;
        return 0;
    }
    std::string stage = argv[1];
    Game game;
    game.Init(stage);
    game.Run();
    return 0;
}