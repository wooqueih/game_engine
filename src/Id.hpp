//
// Created by Michael Pogrebnjak on 16.08.23.
//

#ifndef TOUCHING_GRASS_ID_HPP
#define TOUCHING_GRASS_ID_HPP

class Id {
public:
	static inline unsigned int next() { static unsigned int counter; counter++; return counter; }
};


#endif //TOUCHING_GRASS_ID_HPP
