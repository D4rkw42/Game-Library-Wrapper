#pragma once

#include <vector>

#include <glw/glfw3/Model.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//

// Colorizable Square

inline const std::vector<GLfloat> MESH_SQUARE_MODEL_VERTICES = {
    /////   VERTICES    /////
    -0.5f, 0.5f, 1.0f,
    0.5f, 0.5f, 1.0f,
    -0.5f, -0.5f, 1.0f,
    0.5f, -0.5f, 1.0f
};

inline const std::vector<glw::defs::glfw3::MeshModel::Section> MESH_SQUARE_MODEL_SECTIONS = {
    glw::defs::glfw3::MeshModel::Section(0, 3), // VERTICES
};

inline const std::vector<GLuint> MESH_SQUARE_MODEL_INDICES = {
    0, 1, 2, // firt triangle
    2, 1, 3// second triangle
};

// Texture Square

inline const std::vector<GLfloat> MESH_TEXTURE_SQUARE_MODEL_VERTICES = {
    /////   VERTICES    /////  /////    TEXTURE     /////
    -0.5f, 0.5f, 1.0f,             0.0f, 1.0f,
    0.5f, 0.5f, 1.0f,              1.0f, 1.0f,
    -0.5f, -0.5f, 1.0f,            0.0f, 0.0f,
    0.5f, -0.5f, 1.0f,             1.0f, 0.0f
};

inline const std::vector<glw::defs::glfw3::MeshModel::Section> MESH_TEXTURE_SQUARE_MODEL_SECTIONS = {
    glw::defs::glfw3::MeshModel::Section(0, 3), // VERTICES
    glw::defs::glfw3::MeshModel::Section(3, 2) // TEXTURE
};

inline const std::vector<GLuint> MESH_TEXTURE_SQUARE_MODEL_INDICES = {
    0, 1, 2, // firt triangle
    2, 1, 3// second triangle
};

//

namespace glw::defs::glfw3::models {
    inline glw::defs::glfw3::MeshModel MeshSquareModel = glw::defs::glfw3::MeshModel(
        MESH_SQUARE_MODEL_VERTICES, 3, MESH_SQUARE_MODEL_SECTIONS,
        MESH_SQUARE_MODEL_INDICES, GL_TRIANGLES
    );

    inline glw::defs::glfw3::MeshModel MeshTextureSquareModel = glw::defs::glfw3::MeshModel(
        MESH_TEXTURE_SQUARE_MODEL_VERTICES, 5, MESH_TEXTURE_SQUARE_MODEL_SECTIONS,
        MESH_TEXTURE_SQUARE_MODEL_INDICES, GL_TRIANGLES
    );
}
