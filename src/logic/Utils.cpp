#include "logic/Utils.hpp"

namespace Utils
{
    float dot(const sf::Vector2f &v, const sf::Vector2f &u)
    {
        return v.x * u.x + v.y * u.y;
    }
    float norm(const sf::Vector2f &v)
    {
        return std::sqrt(dot(v, v));
    }
    sf::Vector2f normalize(const sf::Vector2f &v)
    {
        return v / norm(v);
    }
    float sign(float x)
    {
        if (x > 0)
            return 1.f;
        if (x < 0)
            return -1.f;
        return 0.f;
    }
}
