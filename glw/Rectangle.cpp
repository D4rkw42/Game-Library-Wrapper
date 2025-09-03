#include <glw/graphics/geometry/shapes/Rectangle.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glw::graphics::_Rectangle::_Rectangle(void) : glw::graphics::_IShape() {
    this->shader = glw::defs::glfw3::_CreateShader(ISHAPE_SHADER_NAME);
    this->mesh = glw::defs::glfw3::_CreateMeshSquare();
}

void glw::graphics::_Rectangle::_Render(const std::shared_ptr<glw::graphics::_WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const {
    window->_DepthTestConfig(false);

    this->shader._Activate();

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->Width), 0.0f, static_cast<float>(window->Height));
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(x, y, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 0.0f));
    model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::vec4 glColor = glm::vec4(
        static_cast<float>(color.r) / 255,
        static_cast<float>(color.g) / 255,
        static_cast<float>(color.b) / 255,
        color.a
    );

    this->shader._SetUniformMat4("projection", projection);
    this->shader._SetUniformMat4("model", model);
    this->shader._SetUniformVec4("aColor", glColor);

    this->mesh._Render(this->shader);
}
