#include "logic/Game.hpp"

void Game::render(sf::RenderWindow &window)
{
    const float radius{2.f};

    window.clear(sf::Color::Black);

    // PLayer prepare
    sf::CircleShape shape(radius);
    shape.setOrigin({radius, radius});
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(m_player.q());

    // World prepare
    /**
     * We render the world via chunks of width equal the width of the view.
     * We render 3 chunks at a time: a central chunk where the player is, one behind and one in front.
     * The render gets updated only when the player leaves the central chunk.
     */
    sf::View view{window.getView()};
    World& world{m_player.getWorld()};
    float width{view.getSize().x};
    float previous_center_of_chunk{world.getFloor().getBounds().getCenter().x};
    if (
        world.getFloor().getVertexCount() == 0 or
        Utils::abs(m_player.q().x - previous_center_of_chunk) >= 0.5f * width)
    {
        float dx{0.1}; // May want to make it depend on the player speed later.
        float left_margin{m_player.q().x - width / 2.f};
        float x_i{left_margin - width};
        float x_f{left_margin + 2.f * width};
        world.generateFloor(x_i, x_f, dx);
    }

    // Draw
    window.draw(shape);
    window.draw(world.getFloor());

    window.display();
}
