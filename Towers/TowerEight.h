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

	void Fire();

	void Update(double elapsed);

	void SetLocation(double x, double y) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerEight(this); }

private:

	double mTimeTillFire = 5;

	std::vector<std::shared_ptr<CDart> > mDarts;

};

