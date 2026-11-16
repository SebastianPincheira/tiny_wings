#include "objects/World.hpp"

World::World(float width)
    : m_width{width}
{
}

float World::getHeight(float x) const
{
    return std::sin(x);
}

sf::Vector2f World::getTangent(float x) const
{
    sf::Vector2f t{1, std::cos(x)};
    return Utils::normalize(t);
}

sf::Vector2f World::gravity() const
{
    return m_gravity;
}

float World::getWidth() const
{
    return m_width;
}

void World::generateFloor(float x_i, float x_f, float dx)
{
    float width{getWidth()};
    sf::VertexArray floor{sf::PrimitiveType::TriangleStrip};
    for (int n{0}; x_i + n * dx < x_f; ++n)
    {
        float x{x_i + n * dx};
        float fx{getHeight(x)};
        sf::Vertex top{{x, fx}};
        sf::Vertex bot{{x, fx - width}};

        floor.append(top);
        floor.append(bot);
    }
    m_floor = floor;
}

sf::VertexArray World::getFloor(){
    return m_floor;
}
