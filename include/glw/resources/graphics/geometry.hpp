#pragma once

#include <memory>

#include <glw/graphics/geometry/shapes/shapes.hpp>

namespace glw::resources::graphics::geometry {
    inline std::shared_ptr<glw::graphics::_Rectangle> rectangle = nullptr;

    //

    inline void _GenerateResources(void) {
        rectangle = std::make_shared<glw::graphics::_Rectangle>();
    }

    inline void _DeleteResources(void) {
        rectangle = nullptr;
    }
}
