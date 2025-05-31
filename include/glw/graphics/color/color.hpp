#pragma once

namespace glw::graphics {
    /// @brief Represents a RGBA color
    struct Color {
        int red, green, blue;
        float alpha;

        /// @brief Represents a RGBA color
        Color(int red, int green, int blue, float alpha = 1.0f) {
            this->red = red;
            this->green = green;
            this->blue = blue;
            this->alpha = alpha;
        }
    };
}
