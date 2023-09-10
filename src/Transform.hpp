//
// Created by Michael Pogrebnjak on 01.09.23.
//

#ifndef TOUCHING_GRASS_TRANSFORM_HPP
#define TOUCHING_GRASS_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Component.hpp"
#include "glm/detail/type_quat.hpp"

struct Transform: Component {
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::quat orientation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

	inline glm::vec3 getEulerRotation() {
		return glm::vec3(
				atan2((2*(orientation.z * orientation.y + orientation.x * orientation.w)),(1-2*(orientation.x*orientation.x+orientation.y*orientation.y))),
				-1*M_PI*0.5+2*atan2(sqrt(1+2*(orientation.w*orientation.y - orientation.x*orientation.z)), sqrt(1-2*(orientation.w*orientation.y - orientation.x*orientation.z))),
				atan2(2*(orientation.w*orientation.z + orientation.x*orientation.y), 1 - 2*(orientation.y*orientation.y + orientation.z*orientation.z))
		);
	}
	inline void rotate(float angle, glm::vec3 axis) {
		glm::quat rotation = glm::angleAxis(angle, axis);
		orientation = rotation * orientation;
	}
	inline glm::mat4 getMatrix() {
		glm::mat4 scaling = glm::scale(glm::mat4(1.0f), scale);
		glm::mat4 rotation = toMat4(orientation);
		glm::mat4 translation = glm::translate(glm::mat4(1.0f), position);
		return translation * rotation * scaling; }
};

#endif //TOUCHING_GRASS_TRANSFORM_HPP
