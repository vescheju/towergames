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
	CTowerEight(CGame* game);

	/// Default constructor (disabled)
	CTowerEight() = delete;

	/// Copy constructor (disabled)
	CTowerEight(const CTowerEight&) = delete;

	void Update(double elapsed);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitTowerEight(this); }

	void InitializeWeapon() override;

	void AddWeapon() override;

private:

	std::vector<std::shared_ptr<CDart> > mDarts;		///< Vector of darts tower contains

	double mT = 10;			///< Distance of darts from tower while firing

};

