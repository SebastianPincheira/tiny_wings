#include "logic/Game.hpp"

void Game::render(sf::RenderWindow &window) const
{
    const float radius {2.f};
    
    window.clear(sf::Color::Black);

    // PLayer prepare
    sf::CircleShape shape(radius);
    shape.setOrigin({radius, radius});
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(m_player.q());

    // World prepare
    float dx{0.1}; // May want to make it depend on the player speed later.
    sf::View view {window.getView()};
    float width{view.getSize().x};
    float left_margin{view.getCenter().x - width/2.f};
    float x_i {left_margin - width};
    float x_f{left_margin + 2.f * width};
    World world{m_player.getWorld()};
    world.generateFloor(x_i,x_f,dx);

    //Draw
    window.draw(shape);    
    window.draw(world.getFloor());

    window.display();
}
