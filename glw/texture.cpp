#include <glw/glfw3/texture.hpp>

#include <stb_image/stb_image.h>

glw::defs::glfw3::_Texture::_Texture(const std::string& path) {
    stbi_set_flip_vertically_on_load(true);
    GLubyte* bytes = stbi_load(path.c_str(), &this->width, &this->height, &this->channels, 0);

    GLuint texture;
    glGenTextures(1, &texture); // gerando buffer
    glActiveTexture(GL_TEXTURE0); // ativando textura no slot 0 (16 max)

    _Bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    _Unbind();

    stbi_image_free(bytes);
}

glw::defs::glfw3::_Texture::~_Texture() {
    glDeleteTextures(1, &this->ID);
}

void glw::defs::glfw3::_Texture::_Bind(void) const {
    glBindTexture(GL_TEXTURE_2D, this->ID);
}

void glw::defs::glfw3::_Texture::_Unbind(void) const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
