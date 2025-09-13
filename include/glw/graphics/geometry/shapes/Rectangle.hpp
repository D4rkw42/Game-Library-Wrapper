#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/glfw3/Shader.hpp>
#include <glw/glfw3/Mesh.hpp>

constexpr const char* RECTANGLE_FILL_SHADER_PATH = "geometry/rectangle/StaticRectangleFillShader";
constexpr const char* RECTANGLE_STROKE_SHADER_PATH = "geometry/rectangle/StaticRectangleStrokeShader";

namespace glw::graphics {
    class Rectangle {
        public:
            Rectangle(void);
            ~Rectangle() = default;

            void Fill(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const;
            void Stroke(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float width, float height, float border, float angle, const glw::graphics::Color& color) const;

        private:
            glw::defs::glfw3::Shader fillShader, strokeShader;
            glw::defs::glfw3::Mesh mesh;
    };
}
