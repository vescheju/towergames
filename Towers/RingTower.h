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

	void Update(double elapsed) override;

	void SetLocation(double x, double y);

	/// Default constructor (disabled)
	CRingTower() = delete;

	/// Copy constructor (disabled)
	CRingTower(const CRingTower&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRingTower(this); }

private:

	double mTimeTillFire = 5;		///< Time in seconds until next firing of darts

	std::shared_ptr<CRing> mRing;

	bool mFire = false;			///< Boolean represents whether or not currently firing darts

	double mT = 10;			/// Distance of darts from tower while firing
};

