#include <string>

using namespace std;

struct Player {
    /**
     * @brief no brief description
     * a param that shows player's health
     */
    size_t health;
    size_t experience;
    size_t attack;
    string name;

    const static int MAX_LEVEL = 100;
};

int main() {
    Player player1 = { 100, 0, 5, "Joe"};
    Player player2;

    player2.name = "Vasea";
    player2.health = 100;
    player2.attack = 0;
    player2.experience = 5;

    int a = Player::MAX_LEVEL;
    return 0;
}