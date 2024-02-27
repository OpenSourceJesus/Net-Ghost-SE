#ifndef MESH_H
#define MESH_H


#include <string>
#include <vector>

#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "Texture.h"


class Mesh {
public:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	std::vector <Texture> textures; // should be vector of pointers, but won't optimize much.
	glm::mat4 transform; // sends mesh to default model position (same as in blender)

	VAO VAO; 
	
	//VBO & EBO need to have mem cleaned at ~Mesh()!! [memleak]
	//VBO VBO; EBO EBO;

	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures, glm::mat4 transformation = glm::mat4(1.0f));

	void Draw
	(
		Shader& shader,
		Camera& camera,
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
	);
};
#endif
