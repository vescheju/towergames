/**
 * \file TowerEight.h
 *
 * \author Hithesh Yedlapati
 *
 * Tower 8 class derived from CTower
 */

#pragma once
#include "Tower.h"
#include "Dart.h"

#include <vector>
#include <memory>

/**
* releases 8 darts
*/
class CTowerEight :
	public CTower
{
public:
	/// constructor
	CTowerEight(CGame* game);

	/// Default constructor (disabled)
	CTowerEight() = delete;

	/// Copy constructor (disabled)
	CTowerEight(const CTowerEight&) = delete;

	void Update(double elapsed);

	void SetLocation(double x, double y) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerEight(this); }

private:

	double mTimeTillFire = 5;		///< Time in seconds until next firing of darts

	std::vector<std::shared_ptr<CDart> > mDarts;		///< Vector of darts tower contains

	bool mFire = false;			///< Boolean represents whether or not currently firing darts

	double mT = 10;			///< Distance of darts from tower while firing

};

