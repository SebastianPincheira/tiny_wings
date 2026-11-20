#pragma once

#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "objects/World.hpp"
#include "Config.hpp"
#include <iostream>

class Game
{
private:
    World m_world;
    bool m_headless{};

public:
    Game(float q_x, float q_y, float p_x, float p_y, bool headless, float width_of_world);
    void run();
    void processEvents(sf::Window &window) const;
    void update(float dt);
    void render(sf::RenderWindow &window);
};
