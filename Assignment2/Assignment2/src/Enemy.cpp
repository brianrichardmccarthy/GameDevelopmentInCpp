//
//  Enemy.cpp
//

#include "Enemy.hpp"

// Default constructor.
Enemy::Enemy() :
	m_currentTarget({ 0.f, 0.f }) {
	// Set stats.
	m_health = std::rand() % 41 + 80;


	// Set speed.
	m_speed = rand() % 51 + 150;
}

// Overrides the default Update function of Entity.
void Enemy::Update(float timeDelta) {
	// Move towards current target location.
	if (!m_targetPositions.empty()) {
		sf::Vector2f targetLocation = m_targetPositions.front();
		m_velocity = sf::Vector2f(targetLocation.x - m_position.x, targetLocation.y - m_position.y);

		if (abs(m_velocity.x) < 10.f && abs(m_velocity.y) < 10.f) {
			m_targetPositions.erase(m_targetPositions.begin());
		} else {
			float length = sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
			m_velocity.x /= length;
			m_velocity.y /= length;

			m_position.x += m_velocity.x * (m_speed * timeDelta);
			m_position.y += m_velocity.y * (m_speed * timeDelta);

			m_sprite.setPosition(m_position);
		}
	}

	// Call Entity update.
	Entity::Update(timeDelta);
}

// Applies the given amount of damage to the enemy.
void Enemy::Damage(int damage) {
	m_health -= damage;
}

// Checks if the enemy has taken enough damage that they are now dead.
bool Enemy::IsDead() {
	return (m_health <= 0);
}

