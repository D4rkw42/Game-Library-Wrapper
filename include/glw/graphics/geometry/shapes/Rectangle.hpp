#pragma once

#include <glw/graphics/geometry/Shape.hpp>

namespace glw::graphics {
    class _Rectangle : public glw::graphics::_IShape {
        public:
            _Rectangle(void);
            ~_Rectangle() = default;

            void _Render(const std::shared_ptr<glw::graphics::_WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const override final;
    };
}
