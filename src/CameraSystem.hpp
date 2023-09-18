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
	CameraSystem(std::shared_ptr<CameraData> cameraData, std::shared_ptr<Transform> transform) {
		m_cameraData = cameraData;
		m_transform = transform;
	}


	glm::mat4 getViewMatrix() {
		return glm::lookAt(m_transform->position, m_transform->position + m_transform->getForward(), m_transform->getUp());
	}

	glm::mat4 getProjectionMatrix() { return glm::perspective(m_cameraData->yFov, m_cameraData->aspectRatio, m_cameraData->nearClippingDistance, m_cameraData->farClippingDistance); }

	inline void setCameraData(std::shared_ptr<CameraData> cameraData) { m_cameraData = cameraData; }
	inline void setTransform(std::shared_ptr<Transform> transform) { m_transform = transform; }
private:
	std::shared_ptr<CameraData> m_cameraData;
	std::shared_ptr<Transform> m_transform;
};


#endif //CLION_OPENGL_TEST_CAMERA_HPP
