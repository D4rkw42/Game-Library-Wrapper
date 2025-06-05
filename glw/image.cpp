#include <glw/graphics/image/image.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glw::graphics::_Image::_Image(const std::string& shader, const std::string& path) {
    this->shader = glw::defs::glfw3::_CreateShader(shader);
    this->texture = glw::defs::glfw3::_CreateTexture(path);
    this->mesh = glw::defs::glfw3::_CreateMeshTextureSquare();
}

glw::graphics::_Image::_Image(void) {}
glw::graphics::_Image::~_Image() {}

//

void glw::graphics::_Image::_RenderImage(const glw::graphics::_Image& self, const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, int z, float scale) {
    self.shader._Activate();

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->width), 0.0f, static_cast<float>(window->height));
    self.shader._SetUniformMat4("projection", projection);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(x, y, z));
    model = glm::scale(model, glm::vec3(self._GetWidth() * scale, self._GetHeight() * scale, 1.0f));

    self.shader._SetUniformMat4("model", model);

    self.texture._Activate();
    self.texture._Bind();
    self.shader._SetUniformi("tex0", 0);

    self.mesh._Render(self.shader);

    self.texture._Unbind();
}

void glw::graphics::_Image::_Render(const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, int z, float scale) {
    window->_DepthTestConfig(true);
    _RenderImage(*this, window, x, y, z, scale);
}

void glw::graphics::_Image::_Render(const std::shared_ptr<glw::graphics::_Window>& window, int x, int y, float scale) {
    window->_DepthTestConfig(false);
    _RenderImage(*this, window, x, y, 0.0f, scale);
}

int glw::graphics::_Image::_GetWidth(void) const noexcept {
    return this->texture.width;
}

int glw::graphics::_Image::_GetHeight(void) const noexcept {
    return this->texture.height;
}

// // Static Image

// glw::graphics::_StaticImage::_StaticImage(const std::string& path) : _Image("StaticTextureShader", path) {}



// //

// // Dynamic Image

// glw::graphics::_DynamicImage::_DynamicImage(const std::string& path) : _Image("DymanicTextureShader", path) {}
