//
//  Enemy.hpp


#ifndef Enemy_hpp
#define Enemy_hpp

//-------------------------------------------------------------------------------------
// Enemy.h
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Written by Dale Green. Copyright (c) Packt Publishing. All rights reserved.
//-------------------------------------------------------------------------------------


#include "Entity.h"
#include "Level.hpp"

class Enemy : public Entity {
public:
	/**
	 * Default constructor.
	 */
	Enemy();

	/**
	 * Overrides the default Update function of Entity.
	 * @param timeDelta The time that has elapsed since the last update.
	 */
	virtual void Update(float timeDelta) override;

	

	/**
	 * Applies the given amount of damage to the enemy.
	 * @param damage The amount of damage to deal to the enemy.
	 */
	void Damage(int damage);

	/**
	 * Checks if the enemy has taken enough damage that they are now dead.
	 * @return True if the enemy is dead.
	 */
	bool IsDead();

protected:
	
};



#endif /* Enemy_hpp */
