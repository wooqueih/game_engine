//
// Created by Michael Pogrebnjak on 15.08.23.
//

#include "Entity.hpp"

Entity::Entity() {}


void Entity::onStart() {
	for (int i = 0; i < m_children.size(); i++) {
		m_children[i].onStart();
	}
}

void Entity::onUpdate() {
	for (int i = 0; i < m_children.size(); i++) {
		m_children[i].onUpdate();
	}
}

void Entity::onFixedUpdate() {
	for (int i = 0; i < m_children.size(); i++) {
		m_children[i].onFixedUpdate();
	}
}
