#pragma once

#include <memory>

#include <glw/glfw3/Shader.hpp>
#include <glw/glfw3/Mesh.hpp>

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

constexpr const char* ISHAPE_SHADER_NAME = "StaticPrimitiveShader";

namespace glw::graphics {
    class _IShape {
        public:
            _IShape(void) = default;
            virtual ~_IShape() = default;

            virtual void _Render(const std::shared_ptr<glw::graphics::_WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const = 0;

        protected:
            glw::defs::glfw3::_Shader shader;
            glw::defs::glfw3::_Mesh mesh;
    };
}
