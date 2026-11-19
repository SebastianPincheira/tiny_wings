#pragma once

#include <SFML/Graphics.hpp>
#include "logic/Utils.hpp"
#include "Config.hpp"
#include <iostream>
#include <cmath>

struct World
{
private:
    sf::Vector2f m_gravity{0, -Config::GRAVITY}; ///< Gravity of the world.
    float m_width;                               ///< Width of the world.
    sf::VertexArray m_floor{};                     ///< Vertices to render the floor using TriangleStrip.

public:
    /**
     * @brief Initializes a world.
     *
     * @param width Width of the floor.
     */
    World(float width);

    /**
     * @brief Returns f(x) for a given x, where f is such that the floor is the graph of f.
     *
     * @param x Position in the x-axis.
     */
    float getHeight(float x) const;

    /**
     * @brief Returns the tangent vector to the floor given by d/dt|_x (t,f(t)).
     *
     * @param x x-axis value at which the tangent is calculated.
     */
    sf::Vector2f getTangent(float x) const;

    /**
     * @brief Returns the gravity of the world.
     */
    sf::Vector2f gravity() const;

    /**
     * @brief Returns the width of the world.
     */
    float getWidth() const;

    /**
     * @brief Generates the floor of the world to be rendered on a given x-axis interval. Only concerns rendering.
     *
     * @param x_i Inital value (left) of the interval of the world to be generated.
     * @param x_f Final value (right) of the interval of the world to be generated.
     * @param dx x-axis resolution of the floor.
     */
    void generateFloor(float x_i, float x_f, float dx);

    /**
     * @brief Returns the floor vertices for rendering using TriangleStrip.
     */
    sf::VertexArray getFloor();
};
