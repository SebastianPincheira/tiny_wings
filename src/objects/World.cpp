#include "objects/World.hpp"

World::World(float width, float player_q_x, float player_q_y, float player_p_x, float player_p_y)
    : m_width{width}, m_player{player_q_x, player_q_y, player_p_x, player_p_y, *this}
{
}

float World::getHeight(float x) const
{
    return std::sin(x);
}

sf::Vector2f World::getTangent(float x)
{
    const sf::Vector2f t{1, std::cos(x)};
    return Utils::normalize(t);
}

const sf::Vector2f &World::gravity() const
{
    return m_gravity;
}

float World::getWidth() const
{
    return m_width;
}

void World::generateFloor(float x_i, float x_f, float dx)
{
    const float width{getWidth()};
    sf::VertexArray floor{sf::PrimitiveType::TriangleStrip};
    for (int n{0}; x_i + n * dx <= x_f; ++n)
    {
        const float x{x_i + n * dx};
        const float fx{getHeight(x)};
        const sf::Vertex top{{x, fx}};
        const sf::Vertex bot{{x, fx - width}};

        floor.append(top);
        floor.append(bot);
    }
    m_floor = floor;
}

const sf::VertexArray &World::getFloor() const
{
    return m_floor;
}

sf::VertexArray &World::getFloor()
{
    return m_floor;
}

const Player &World::getPlayer() const
{
    return m_player;
}

Player &World::getPlayer()
{
    return m_player;
}
