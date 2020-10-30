/**
 * \file PumpkinTower.h
 *
 * \author Zach Arnold
 *
 * Derived from CBombTower, explosion tower explodes in multiple directions
 */

#pragma once
#include "BombTower.h"

/**
* pumpkin bomb tower class
*/
class CPumpkinTower 
	: public CBombTower
{
public:
	/// constructor
	CPumpkinTower(CGame* game);

	/// Default constructor (disabled)
	CPumpkinTower() = delete;

	/// Copy constructor (disabled)
	CPumpkinTower(const CPumpkinTower&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPumpkinTower(this); }

	void InitializeWeapon() override;

	void AddWeapon() override;
};

