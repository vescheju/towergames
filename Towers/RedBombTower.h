/**
 * \file RedBombTower.h
 *
 * \author Zach Arnold
 *
 * Derived from CBombTower, explosion tower every 3 seconds
 */

#pragma once
#include "BombTower.h"

/**
* normal bomb tower class
*/
class CRedBombTower 
	: public CBombTower
{
public:
	/// constructor
	CRedBombTower(CGame* game);

	/// Default constructor (disabled)
	CRedBombTower() = delete;

	/// Copy constructor (disabled)
	CRedBombTower(const CRedBombTower&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRedBombTower(this); }

	void InitializeWeapon() override;

	void AddWeapon() override;
};

