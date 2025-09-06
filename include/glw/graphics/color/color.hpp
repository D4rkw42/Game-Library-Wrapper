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

    // Predefined colors
    namespace Colors {
        inline const Color BLACK = Color(0, 0, 0);
        inline const Color RED = Color(255, 0, 0);
        inline const Color GREEN = Color(0, 255, 0);
        inline const Color BLUE = Color(0, 0, 255);
        inline const Color WHITE = Color(255, 255, 255);
    }
}
