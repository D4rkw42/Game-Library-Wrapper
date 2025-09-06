#pragma once

#include <glw/graphics/geometry/Shape.hpp>

namespace glw::graphics {
    class Circunference: public glw::graphics::IShape {
        public:
            Circunference(void);
            ~Circunference() = default;

            void Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const override final;
    };
}
