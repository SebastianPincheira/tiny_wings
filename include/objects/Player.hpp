#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Config.hpp"
#include "logic/Utils.hpp"

class World;

class Player
{
private:
    sf::Vector2f m_q{};               ///< Playe's position.
    sf::Vector2f m_p{};               ///< Player's velocity.
    bool m_falling{false};            ///< Weather the player is falling faster. Tuggled by the user.
    World &m_world;                   ///< The world the player inhabits.
    bool touchedFloorLastIter{false}; ///< Weather the player touched the floor on it's previous position.

public:
    /**
     * @brief Initializes a player.
     * Defines the player initial position and velocity.
     *
     * @param q_x Player's x-axis initial position.
     * @param q_y Player's y-axis initial position.
     * @param p_x Player's x-axis initial velocity.
     * @param p_x Player's y-axis initial velocity.
     */
    Player(float q_x, float q_y, float p_x, float p_y, World &world);

    /**
     * @brief Gives the speed of the player.
     */
    float getSpeed() const;

    /**
     * @brief Gets the right rotation of the player for its given speed.
     */
    float getRotation() const;

    /**
     * @brief Gets the height of the player with respect to the floo right under it.
     */
    float getHeight() const;

    /**
     * @brief Updates position of the player.
     *
     * @param dt Time step (in seconds) used for the velocity update.
     */
    void move(float dt);

    /**
     * @brief Updates velocity of the player.
     *
     * When the player is airborne, gravity is applied directly.
     * When the player is on the ground, gravity is projected onto the
     * terrain's tangent direction.
     *
     * @param dt Time step (in seconds) used for the velocity update.
     */
    void redirect(float dt);

    /**
     * @brief Gets a constant reference to the position of the player.
     */
    const sf::Vector2f &q() const;

    /**
     * @brief Gets a reference to the position of the player.
     */
    sf::Vector2f &q();

    /**
     * @brief Gets a constant reference to the velocity of the player.
     */
    const sf::Vector2f &p() const;

    /**
     * @brief Gets a reference to the velocity of the player.
     */
    sf::Vector2f &p();

    /**
     * @brief Updates the state of `touchedFloorLastIter` to reflect the state of the player on the last iter.
     */
    void updateTouchedFloorLastIter();

    /**
     * @brief Gets a constant reference to the world the player inhabits.
     */
    const World &getWorld() const;
};
