#pragma once

#include <limits>

namespace glw::math {
    /// @brief pi constant value
    constexpr float PI = 3.1415927f;
    /// @brief phi constant value
    constexpr float PHI = 1.6180339f;
    /// @brief euler constant value
    constexpr float EULER = 2.7182818f;

    /// @brief NaN definition
    constexpr float NaN = std::numeric_limits<float>::quiet_NaN();
}
