#include "logic/Game.hpp"
#include <iostream>

int main()
{
    float widht_of_world{20}; // This is meant to be temporary magic number.
    Game game{0.1f, 25.f, 0.f, 0.0f, false, widht_of_world};
    game.run();

    return 0;
}
