//
// Created by Michael Pogrebnjak on 15.08.23.
//

#ifndef TOUCHING_GRASS_ENTITY_HPP
#define TOUCHING_GRASS_ENTITY_HPP

#include <vector>
#include <string>
#include <memory>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/detail/type_quat.hpp>

#include "System.hpp"
#include "Component.hpp"
#include "Transform.hpp"

/*struct Transform {
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
};*/
class Entity {
public:
	Entity();
	void onStart();
	void onUpdate();
	void onFixedUpdate();

	inline Entity& addChild() { m_children.push_back(Entity()); return m_children[m_children.size()-1]; };

	template<typename T> inline T* addComponent(T component) { m_components.push_back(component); return static_cast<T*>(&m_components[m_components.size()-1]); }

	template<typename T> T* getComponent() {
		for (int i = 0; i < m_components.size(); i++) {
			if (typeid(T) == typeid(m_components[i])) {
				return static_cast<T*>(&m_components[i]);
			}
		}
		return NULL;
	}

	template<typename T> inline T* addSystem(T system) { m_systems.push_back(system); return static_cast<T*>(&m_systems[m_systems.size()-1]); }

	template<typename T> T* getSystem() {
		for (int i = 0; i < m_systems.size(); i++) {
			if (typeid(T) == typeid(m_systems[i])) {
				return static_cast<T*>(&m_systems[i]);
			}
		}
		return NULL;
	}
	std::string m_name;
private:
	std::vector<Entity> m_children;
	std::vector<Component> m_components;
	std::vector<System> m_systems;
};


#endif //TOUCHING_GRASS_ENTITY_HPP
