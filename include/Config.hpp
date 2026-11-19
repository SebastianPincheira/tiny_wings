#pragma once
#include <numbers>

namespace Config
{
    constexpr unsigned int WINDOW_WIDTH{1920};  ///< The width of the window openned for the game.
    constexpr unsigned int WINDOW_HEIGHT{1080}; ///< The height of the window openned for the game.

    constexpr float GRAVITY{9.80665f}; ///< Gravity used for the physics.
    constexpr float ELLASTICITY{1.f}; ///< Ellasticity of the playe-world colisions.
    constexpr float LOGIC_HZ{120.f};   ///< Frequency at which the game logic runs.
    constexpr float RENDER_HZ{60.f};   ///< Frequency of the rendering (fps).

    constexpr float PI{3.14159265358979323846264338327950288419716f}; ///< The area of the unit circle.
    constexpr float epsilon{0.1f};                                    ///< Small variable used for small quantities.
}
