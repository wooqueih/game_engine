//
// Created by Michael Pogrebnjak on 15.08.23.
//

#ifndef TOUCHING_GRASS_SCENE_HPP
#define TOUCHING_GRASS_SCENE_HPP

#include <vector>

#include "CameraSystem.hpp"
#include "Entity.hpp"

class Scene {
public:
	Scene();
	void start();
	void update();
	void fixedUpdate();
	inline Entity& getSceneEntity() { return m_sceneEntity; }
	/*inline void setActiveCamera(std::shared_ptr<Camera> camera) { m_activeCamera = camera; }
	inline std::shared_ptr<Camera> getActiveCamera() { return m_activeCamera; }*/
private:
	//std::shared_ptr<Camera> m_activeCamera;
	Entity m_sceneEntity;
};


#endif //TOUCHING_GRASS_SCENE_HPP
