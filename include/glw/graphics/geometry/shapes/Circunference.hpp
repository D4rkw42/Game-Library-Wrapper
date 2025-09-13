#pragma once

#include <glw/graphics/Window.hpp>
#include <glw/graphics/color/Color.hpp>

#include <glw/glfw3/Shader.hpp>
#include <glw/glfw3/Mesh.hpp>

constexpr const char* CIRCUNFERENCE_FILL_SHADER_PATH = "geometry/circunference/StaticCircunferenceFillShader";
constexpr const char* CIRCUNFERENCE_STROKE_SHADER_PATH = "geometry/circunference/StaticCircunferenceStrokeShader";

namespace glw::graphics {
    class Circunference {
        public:
            Circunference(void);
            ~Circunference() = default;

            void Fill(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float diameter, const glw::graphics::Color& color) const;
            void Stroke(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float diameter, float border, const glw::graphics::Color& color) const;

        private:
            glw::defs::glfw3::Shader fillShader, strokeShader;
            glw::defs::glfw3::Mesh mesh;
    };
}
