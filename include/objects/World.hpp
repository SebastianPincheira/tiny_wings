#pragma once

#include <SFML/Graphics.hpp>
#include "logic/Utils.hpp"
#include "Config.hpp"

struct World
{
private:
    sf::Vector2f m_gravity{0, -Config::GRAVITY};
    float m_width;
    sf::VertexArray m_floor{
        sf::PrimitiveType::TriangleStrip, 0};

public:
    World(float width);
    double getHeight(float x) const;
    sf::Vector2f getTangent(float x) const;
    sf::Vector2f gravity() const;
    float getWidth() const;
    float append(sf::Vertex vertex);
    float popFirst();
};
