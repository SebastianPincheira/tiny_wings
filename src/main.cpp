#include "logic/Game.hpp"
#include <iostream>

int main()
{
    Game game{0.1f, 25.f, 0.f, 0.0f, false};
    game.run();

    return 0;
}
