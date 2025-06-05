#pragma once

#include <memory>
#include <string>

#include <glw/glfw3/shader.hpp>
#include <glw/glfw3/mesh.hpp>
#include <glw/glfw3/texture.hpp>

#include <glw/graphics/window.hpp>

namespace glw::graphics {
    class _Image {
        public:
            _Image(const std::string& shader, const std::string& path);
            _Image(void);

            ~_Image();

            void _Render(const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, int z, float scale = 1.0f);
            void _Render(const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, float scale = 1.0f);

            int _GetWidth(void) const noexcept;
            int _GetHeight(void) const noexcept;

            _Image(_Image&& other) {
                this->shader = std::move(other.shader);
                this->mesh = std::move(other.mesh);
                this->texture = std::move(other.texture);
            }

            _Image& operator=(_Image&& other) {
                this->shader = std::move(other.shader);
                this->mesh = std::move(other.mesh);
                this->texture = std::move(other.texture);

                return *this;
            }


            private:
            glw::defs::glfw3::_Shader shader;
            glw::defs::glfw3::_Mesh mesh;
            glw::defs::glfw3::_Texture texture;

            static void _RenderImage(const glw::graphics::_Image& self, const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, int z, float scale);
    };

    // class _StaticImage : public _Image {
    //     public:
    //         _StaticImage(const std::string& path);
    //         ~_StaticImage() = default;
    // };

    // class _DynamicImage : public _Image {
    //     public:
    //         _DynamicImage(const std::string& path);
    //         ~_DynamicImage() = default;

    //         // implementar câmera antes
    //         // isso tá certo? EU não ia usar camera::SceneViewer?
    //         // void Render(const std::shared_ptr<>& camera, int x, int y, float scale = 1.0f);
    // };

    // //

    // inline std::shared_ptr<_Image> _CreateStaticImage(const std::string& path) { // verificar se não vai lançar exceção
    //     std::shared_ptr<_StaticImage> mImage = std::make_shared<_StaticImage>(path);
    //     return std::dynamic_pointer_cast<_Image>(mImage);
    // }

    // inline std::shared_ptr<_Image> _CreateDynamicImage(const std::string& path) { // verificar se não vai lançar exceção
    //     std::shared_ptr<_DynamicImage> mImage = std::make_shared<_DynamicImage>(path);
    //     return std::dynamic_pointer_cast<_Image>(mImage);
    // }
}
