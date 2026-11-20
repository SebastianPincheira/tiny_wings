#include "logic/Game.hpp"

void Game::render(sf::RenderWindow &window)
{
    const Player& player{m_world.getPlayer()};
    constexpr float radius{2.f};
    sf::VertexArray & floor{m_world.getFloor()};

    window.clear(sf::Color::Black);

    // PLayer prepare
    sf::CircleShape shape(radius);
    shape.setOrigin({radius, radius});
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(player.q());

    // world prepare
    /**
     * We render the world via chunks of width equal the width of the view.
     * We render 3 chunks at a time: a central chunk where the player is, one behind and one in front.
     * The render gets updated only when the player leaves the central chunk.
     */
    sf::View view{window.getView()};
    float width{view.getSize().x};
    float previous_center_of_chunk{floor.getBounds().getCenter().x};
    if (
        floor.getVertexCount() == 0 or
        Utils::abs(player.q().x - previous_center_of_chunk) >= 0.5f * width)
    {
        float dx{0.1}; // May want to make it depend on the player speed later.
        float left_margin{player.q().x - width / 2.f};
        float x_i{left_margin - width};
        float x_f{left_margin + 2.f * width};
        m_world.generateFloor(x_i, x_f, dx);
    }

    // Draw
    window.draw(shape);
    window.draw(floor);

    window.display();
}
