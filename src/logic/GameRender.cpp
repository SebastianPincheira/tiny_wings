#include "logic/Game.hpp"

void Game::render(sf::RenderWindow &window) const
{
    const float radius {2.f};
    
    window.clear(sf::Color::Black);

    sf::CircleShape shape(radius);
    shape.setOrigin({radius, radius});
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(m_player.q());
    window.draw(shape);

    window.display();
}
