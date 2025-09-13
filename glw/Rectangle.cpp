#include <glw/graphics/geometry/shapes/Rectangle.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glw/utils/math/math.hpp>

glw::graphics::Rectangle::Rectangle(void) : glw::graphics::IShape() {
    this->shader = glw::defs::glfw3::CreateShader(ISHAPE_SHADER_NAME);
    this->mesh = glw::defs::glfw3::CreateMeshSquare();
}

void glw::graphics::Rectangle::Render(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float width, float height, float angle, const glw::graphics::Color& color) const {
    window->DepthTestConfig(false);
    window->BlendingConfig(true);

    this->shader.Activate();

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

    this->shader.SetUniformMat4("projection", projection);
    this->shader.SetUniformMat4("model", model);
    this->shader.SetUniformVec4("aColor", glColor);

    this->mesh.Render(this->shader);
}
