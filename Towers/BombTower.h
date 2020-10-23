/**
 * \file BombTower.h
 *
 * \author Hithesh Yedlapati
 *
 * Derived from CTower, explosion tower every 3 seconds
 */

#pragma once
#include "Tower.h"

class CExplosion;

/**
* bomb explodes in certain time period given to constructor, then removed
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

	void Update(double elapsed) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBombTower(this); }

	void CBombTower::SetLocation(double x, double y);

	/** Getter function for mDetonated member
	 * \return bool representing whether or not bomb's been detonated
	 */
	bool IsDetonated() const { return mDetonated; }

private:

	std::shared_ptr<CExplosion> mExplosion;			///< Explosion object that tower detonates

	bool mDetonated = false;		///< Bool value of whether or not bomb has been detonated
};

