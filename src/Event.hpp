//
// Created by Michael Pogrebnjak on 15.08.23.
//

#ifndef TOUCHING_GRASS_EVENT_HPP
#define TOUCHING_GRASS_EVENT_HPP

#include <vector>
#include <string>

class EventHandler {
public:
	EventHandler();

	unsigned int registerEvent();
private:
	std::vector<std::vector<void (*)()>> m_eventRegistry;
};


#endif //TOUCHING_GRASS_EVENT_HPP
