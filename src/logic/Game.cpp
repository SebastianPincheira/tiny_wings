#include "logic/Game.hpp"

Game::Game(float q_x, float q_y, float p_x, float p_y, bool headless)
    : m_player{q_x, q_y, p_x, p_y}, m_headless{headless}
{
}

void Game::run()
{
    bool isRunning;
    if (m_headless)
    {
        sf::Clock clock;
        while (true)
        { // Here I will have to implement the headless version. I need to implement Python events.
            sf::Time dt = clock.restart();
            update(dt.asSeconds());
        }
    }
    else
    {
        const sf::Vector2f ratio{1920.f, -1080.f};
        sf::RenderWindow window(
            sf::VideoMode(
                {static_cast<unsigned int>(ratio.x), static_cast<unsigned int>(-ratio.y)}
            ), "Tiny Wings"
        );
        sf::View view({0.f, -(1.f/20.f) * ratio.y/4.f}, (1.f / 10.f) * ratio);

        window.setVerticalSyncEnabled(true);
        window.setView(view);

        sf::Clock clock;
        while (window.isOpen())
        {
            processEvents(window);

            sf::Time dt = clock.restart();
            update(dt.asSeconds());

            render(window);
        }
    }
}
