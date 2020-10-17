/**
 * \file Ring.h
 *
 * \author Hithesh Yedlapati
 *
 * Class for creating Ring around CRingTower
 */

#pragma once
#include "Item.h"

/**
* CRing class creates ring that increases over time
* derived from CItem
*/
class CRing : public CItem
{
public:
	/// constructor
	CRing(CGame* game);

	/// constructor disabled
	CRing() = delete;

	/// copy constructor
	CRing(const CRing&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRing(this); }

private:
	/// radius or ring, initialized to 10 pixels
	double mRadius = 10;
};

