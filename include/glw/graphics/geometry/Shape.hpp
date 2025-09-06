#pragma once

#include <memory>

#include <glw/glfw3/Shader.hpp>
#include <glw/glfw3/Mesh.hpp>

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

constexpr const char* ISHAPE_SHADER_NAME = "StaticPrimitiveShader";
constexpr const char* CIRCUNFERENCE_SHADER_NAME = "StaticCircunferenceShader";

namespace glw::graphics {
    class IShape {
        public:
            IShape(void) = default;
            virtual ~IShape() = default;

            virtual void Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const = 0;

        protected:
            glw::defs::glfw3::Shader shader;
            glw::defs::glfw3::Mesh mesh;
    };
}
