#pragma once

#include <SFML/Graphics.hpp>
#include "logic/Utils.hpp"
#include "Config.hpp"
#include <iostream>
#include <cmath>

struct World
{
private:
    sf::Vector2f m_gravity{0, -Config::GRAVITY};
    float m_width;
    sf::VertexArray m_floor;

public:
    World(float width);
    float getHeight(float x) const;
    sf::Vector2f getTangent(float x) const;
    sf::Vector2f gravity() const;
    float getWidth() const;
    void generateFloor(float x_i, float x_f, float dx);
    sf::VertexArray getFloor();
};
