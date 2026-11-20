#pragma once

#include <SFML/Graphics.hpp>
#include "logic/Utils.hpp"
#include "Config.hpp"
#include "objects/Player.hpp"
#include <iostream>
#include <cmath>

struct World
{
private:
    sf::Vector2f m_gravity{0, -Config::GRAVITY}; ///< Gravity of the world.
    float m_width;                               ///< Width of the world.
    sf::VertexArray m_floor{};                   ///< Vertices to render the floor using TriangleStrip.
    Player m_player;                             ///< The player in the world.

public:
    /**
     * @brief Initializes a world.
     *
     * @param width Width of the floor.
     * @param q_x Player's x-axis initial position.
     * @param q_y Player's y-axis initial position.
     * @param p_x Player's x-axis initial velocity.
     * @param p_x Player's y-axis initial velocity.
     */
    World(float width, float player_q_x, float player_q_y, float player_p_x, float player_p_y);

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
    sf::Vector2f getTangent(float x);

    /**
     * @brief Returns constant reference to the gravity of the world.
     */
    const sf::Vector2f& gravity() const;

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
     * @brief Returns a constant reference to the floor vertices for rendering using TriangleStrip.
     */
    const sf::VertexArray &getFloor() const;

    /**
     * @brief Returns a reference to the floor vertices for rendering using TriangleStrip.
     */
    sf::VertexArray &getFloor();

    /**
     * @brief Returns a constant reference to the player in the world.
     */
    const Player &getPlayer() const;

    /**
     * @brief Returns a reference to the player in the world.
     */
    Player &getPlayer();
};
