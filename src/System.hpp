//
// Created by Michael Pogrebnjak on 02.09.23.
//

#ifndef TOUCHING_GRASS_SYSTEM_HPP
#define TOUCHING_GRASS_SYSTEM_HPP

class System {
public:
	virtual ~System() {};

	virtual void onAttach() {};
	virtual void onDetach() {};
	virtual void onUpdate() {};
	virtual void onFixedUpdate() {};
};

#endif //TOUCHING_GRASS_SYSTEM_HPP
