#include "logic/Game.hpp"

void Game::update(float dt)
{
    m_world.getPlayer().redirect(dt);
    m_world.getPlayer().move(dt);
}
