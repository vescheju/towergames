/**
 * \file BombTower.h
 *
 * \author Hithesh Yedlapati
 *
 * Derived from CTower, explosion tower every 3 seconds
 */

#pragma once
#include "Tower.h"

/**
* bomb explodes every 3 seconds
*/
class CBombTower :
	public CTower
{
public:
	/// constructor
	CBombTower(CGame* game);

	/// Default constructor (disabled)
	CBombTower() = delete;

	/// Copy constructor (disabled)
	CBombTower(const CBombTower&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBomb(this); }

private:
	/// time bomb tower
	int mSeconds = 0;
};

