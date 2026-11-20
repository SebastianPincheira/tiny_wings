#include "logic/Game.hpp"

constexpr sf::Time logic_period{sf::seconds(1.f / Config::LOGIC_HZ)};
constexpr sf::Time render_period{sf::seconds(1.f / Config::RENDER_HZ)};

Game::Game(float q_x, float q_y, float p_x, float p_y, bool headless, float width)
    : m_world{width, q_x, q_y, p_x, p_y}, m_headless{headless}
{
}

void Game::run()
{
    if (m_headless)
    {
        sf::Clock logic_clock;
        while (true)
        { // I need to implement Python events.
            if (logic_clock.getElapsedTime() >= logic_period)
            {
                const sf::Time dt = logic_clock.restart();
                update(dt.asSeconds());
            }
        }
    }
    else
    {
        const sf::Vector2f ratio{1920.f, -1080.f};
        sf::RenderWindow window(
            sf::VideoMode(
                {static_cast<unsigned int>(ratio.x),
                 static_cast<unsigned int>(-ratio.y)}),
            "Tiny Wings");
        sf::View view(
            {0.f, -(1.f / 20.f) * ratio.y / 4.f},
            (1.f / 10.f) * ratio);

        window.setVerticalSyncEnabled(true);
        window.setView(view);

        sf::Clock logic_clock;
        sf::Clock render_clock;
        while (window.isOpen())
        {
            processEvents(window);

            if (logic_clock.getElapsedTime() >= logic_period)
            {
                const sf::Time dt = logic_clock.restart();
                update(dt.asSeconds());
            }
            if (render_clock.getElapsedTime() >= render_period)
            {
                render(window);
            }
        }
    }
}
