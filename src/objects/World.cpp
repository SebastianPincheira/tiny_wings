#include "objects/World.hpp"

World::World(float width)
    : m_width{width}
{   
}

double World::getHeight(float x) const
{
    return x * x;
}

sf::Vector2f World::getTangent(float x) const
{
    sf::Vector2f t{1, 2.f * x};
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

float World::append(sf::Vertex vertex){
    m_floor.append(vertex)
}
float World::popFirst(){
    
}
