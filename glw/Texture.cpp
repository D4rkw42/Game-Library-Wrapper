#include <glw/glfw3/Texture.hpp>

#include <stb_image/stb_image.h>

glw::defs::glfw3::Texture::Texture(const std::string& path) {
    stbi_set_flip_vertically_on_load(true);
    GLubyte* bytes = stbi_load(path.c_str(), &this->width, &this->height, &this->channels, 0);

    GLint internalFormat;
    GLenum dataFormat;

    switch (this->channels) {
        case 1:
            internalFormat = GL_RED;
            dataFormat = GL_RED;
            break;
        case 3:
            internalFormat = GL_RGB;
            dataFormat = GL_RGB;
            break;
        case 4:
            internalFormat = GL_RGBA;
            dataFormat = GL_RGBA;
            break;
        default:
            // error
    }

    GLuint texture;
    glGenTextures(1, &texture); // gerando buffer

    this->ID = texture;

    Activate();
    Bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, this->width, this->height, 0, dataFormat, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);

    Unbind();
}

glw::defs::glfw3::Texture::Texture(void) {}

glw::defs::glfw3::Texture::~Texture() {
    if (this->ID != 0) {
        glDeleteTextures(1, &this->ID);
    }
}

void glw::defs::glfw3::Texture::Bind(void) const {
    GLint currTexture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &currTexture);

    if (currTexture != this->ID) {
        glBindTexture(GL_TEXTURE_2D, this->ID);
    }
}

void glw::defs::glfw3::Texture::Unbind(void) const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void glw::defs::glfw3::Texture::Activate(void) const {
    GLint activeTexture;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTexture);

    if (activeTexture != GL_TEXTURE0) {
        glActiveTexture(GL_TEXTURE0);
    }
}
