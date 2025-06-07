#pragma once

namespace glw::graphics {
    /// @brief Represents a RGBA color
    struct Color {
        int r, g, b;
        float a;

        /// @brief Represents a RGBA color
        Color(int red, int green, int blue, float alpha = 1.0f) {
            this->r = red;
            this->g = green;
            this->b = blue;
            this->a = alpha;
        }
    };
}
