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
* bomb explodes every 3 seconds
*/
class CBombTower :
	public CTower
{
public:
	/// constructor
	CBombTower(CGame* game, double timeToDetonate);

	/// Default constructor (disabled)
	CBombTower() = delete;

	/// Copy constructor (disabled)
	CBombTower(const CBombTower&) = delete;

	void Update(double elapsed) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBomb(this); }

	void CBombTower::SetLocation(double x, double y);

private:

	std::shared_ptr<CExplosion> mExplosion;

	bool mDetonated = false;
};

