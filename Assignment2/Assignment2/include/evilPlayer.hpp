//
//  evilPlayer.hpp
//  AssetManagerv1
//
//  Created by Denis Flynn on 16/10/2018.
//  Copyright © 2018 Denis Flynn. All rights reserved.
//

#ifndef evilPlayer_hpp
#define evilPlayer_hpp
#include "utils.h"
#include "Player.h"
#include "Enemy.hpp"

class evilPlayer : public Enemy {
public:
	/**
	 * Default constructor.
	 */
	evilPlayer();
	void Update(float timeDelta);
	void setEvilState();
	// Recalculates the enemies path finding.
	void UpdatePathfinding(Level& level, sf::Vector2f playerPosition);

protected:
	/**
	 * The target position of the enemy.
	 */
	std::vector<sf::Vector2f> m_targetPositions;

	/**
	 * The current target of the enemy.
	 */
	sf::Vector2f m_currentTarget;
};

#endif /* evilPlayer_hpp */
