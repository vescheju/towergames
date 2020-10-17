/**
 * \file RingTower.h
 *
 * \author Hithesh Yedlapati
 *
 * Ring Tower class
 */

#pragma once
#include "Tower.h"

/**
* balloon pops if in the range of the increasing ring
*/
class CRingTower :
	public CTower
{
public:
	/// constructor
	CRingTower(CGame* game);

	/// Default constructor (disabled)
	CRingTower() = delete;

	/// Copy constructor (disabled)
	CRingTower(const CRingTower&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRingTower(this); }

private:
};

