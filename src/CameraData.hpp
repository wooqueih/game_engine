//
// Created by Michael Pogrebnjak on 02.09.23.
//

#ifndef TOUCHING_GRASS_CAMERADATA_HPP
#define TOUCHING_GRASS_CAMERADATA_HPP

#include "Component.hpp"

struct CameraData: Component {
	float nearClippingDistance;
	float farClippingDistance;
	float yFov;
	float aspectRatio;
};

#endif //TOUCHING_GRASS_CAMERADATA_HPP
