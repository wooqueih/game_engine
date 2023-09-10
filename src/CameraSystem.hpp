//
// Created by Michael Pogrebnjak on 27.07.23.
//

#ifndef CLION_OPENGL_TEST_CAMERA_HPP
#define CLION_OPENGL_TEST_CAMERA_HPP

#include <memory>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "System.hpp"
#include "Transform.hpp"
#include "CameraData.hpp"


class CameraSystem : public System {
public:
	CameraSystem() {};
	CameraSystem(CameraData* cameraData, Transform* transform) {
		m_cameraData = cameraData;
		m_transform = transform;
	}

	glm::mat4 getViewMatrix() {
		glm::vec3 target = glm::axis(m_transform->orientation);
		glm::qua rotatedUp = glm::inverse(m_transform->orientation) * glm::qua(0.0f, 1.0f, 0.0f, 0.0f) * m_transform->orientation;
		glm::vec3 up = glm::vec3(rotatedUp.x, rotatedUp.y, rotatedUp.z);
		return glm::lookAt(m_transform->position, m_transform->position + target, up);
	}

	glm::mat4 getProjectionMatrix() { return glm::perspective(m_cameraData->yFov, m_cameraData->aspectRatio, m_cameraData->nearClippingDistance, m_cameraData->farClippingDistance); }

	inline void setCameraData(CameraData* cameraData) { m_cameraData = cameraData; }
	inline void setTransform(Transform* transform) { m_transform = transform; }
private:
	CameraData* m_cameraData;
	Transform* m_transform;
};


#endif //CLION_OPENGL_TEST_CAMERA_HPP
