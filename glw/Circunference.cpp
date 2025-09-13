#include <glw/graphics/geometry/shapes/Circunference.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glw/utils/math/math.hpp>

glw::graphics::Circunference::Circunference(void) {
    this->fillShader = glw::defs::glfw3::CreateShader(CIRCUNFERENCE_FILL_SHADER_PATH);
    this->strokeShader = glw::defs::glfw3::CreateShader(CIRCUNFERENCE_STROKE_SHADER_PATH);

    this->mesh = glw::defs::glfw3::CreateMeshSquare();
}

void glw::graphics::Circunference::Fill(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float diameter, const glw::graphics::Color& color) const {
    window->DepthTestConfig(false);
    window->BlendingConfig(true);

    this->fillShader.Activate();

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->Width), 0.0f, static_cast<float>(window->Height));
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(x, y, 0.0f));
    model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(diameter, diameter, 0.0f));

    glm::vec4 glColor = glm::vec4(
        glw::math::Remap(color.r, 0, 255, 0.0f, 1.0f),
        glw::math::Remap(color.g, 0, 255, 0.0f, 1.0f),
        glw::math::Remap(color.b, 0, 255, 0.0f, 1.0f),
        color.a
    );

    this->fillShader.SetUniformMat4("projection", projection);
    this->fillShader.SetUniformMat4("model", model);
    this->fillShader.SetUniformVec4("aColor", glColor);

    this->mesh.Render(this->fillShader);
}

void glw::graphics::Circunference::Stroke(const std::shared_ptr<glw::graphics::WindowWrapper>& window, int x, int y, float diameter, float border, const glw::graphics::Color& color) const {
    window->DepthTestConfig(false);
    window->BlendingConfig(true);

    this->strokeShader.Activate();

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window->Width), 0.0f, static_cast<float>(window->Height));
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(x, y, 0.0f));
    model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(diameter, diameter, 0.0f));

    glm::vec4 glColor = glm::vec4(
        glw::math::Remap(color.r, 0, 255, 0.0f, 1.0f),
        glw::math::Remap(color.g, 0, 255, 0.0f, 1.0f),
        glw::math::Remap(color.b, 0, 255, 0.0f, 1.0f),
        color.a
    );

    this->strokeShader.SetUniformMat4("projection", projection);
    this->strokeShader.SetUniformMat4("model", model);
    this->strokeShader.SetUniformVec4("aColor", glColor);

    this->strokeShader.SetUniformf("aBorder", border);
    this->strokeShader.SetUniformf("aDiameter", diameter);

    this->mesh.Render(this->strokeShader);
}
