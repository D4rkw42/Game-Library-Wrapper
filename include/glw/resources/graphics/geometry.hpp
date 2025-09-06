#pragma once

#include <memory>

#include <glw/graphics/geometry/shapes/shapes.hpp>

namespace glw::resources::graphics::geometry {
    inline std::shared_ptr<glw::graphics::Rectangle> rectangle = nullptr;
    inline std::shared_ptr<glw::graphics::Circunference> circunference = nullptr;

    //

    inline void GenerateResources(void) {
        rectangle = std::make_shared<glw::graphics::Rectangle>();
        circunference = std::make_shared<glw::graphics::Circunference>();
    }

    inline void DeleteResources(void) {
        rectangle = nullptr;
        circunference = nullptr;
    }
}
