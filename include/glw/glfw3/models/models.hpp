#pragma once

#include <vector>

#include <glw/glfw3/model.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

//

inline const std::vector<GLfloat> MESH_TEXTURE_SQUARE_MODEL_VERTICES = {
    /////   VERTICES    /////  /////    TEXTURE     /////
    -0.5f, 0.5f, 1.0f,             0.0f, 1.0f,
    0.5f, 0.5f, 1.0f,              1.0f, 1.0f,
    -0.5f, -0.5f, 1.0f,            0.0f, 0.0f,
    0.5f, -0.5f, 1.0f,             1.0f, 0.0f
};

inline const std::vector<glw::defs::glfw3::_MeshModel::_Section> MESH_TEXTURE_SQUARE_MODEL_SECTIONS {
    glw::defs::glfw3::_MeshModel::_Section(0, 3), // VERTICES
    glw::defs::glfw3::_MeshModel::_Section(3, 2) // TEXTURE
};

inline const std::vector<GLuint> MESH_TEXTURE_SQUARE_MODEL_INDICES = {
    0, 1, 2, // firt triangle
    2, 1, 3// second triangle
};

//

namespace glw::defs::glfw3::models {
    inline glw::defs::glfw3::_MeshModel MeshTextureSquareModel = glw::defs::glfw3::_MeshModel(
        MESH_TEXTURE_SQUARE_MODEL_VERTICES, 5, MESH_TEXTURE_SQUARE_MODEL_SECTIONS,
        MESH_TEXTURE_SQUARE_MODEL_INDICES, GL_TRIANGLES
    );
}
