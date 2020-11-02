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

	CRingTower(CGame* game);

	/// Default constructor (disabled)
	CRingTower() = delete;

	/// Copy constructor (disabled)
	CRingTower(const CRingTower&) = delete;

	void Update(double elapsed) override;


	/**
	* Getter for the ring object of the tower
	* 
	* \return pointer to the ring of the tower
	*/
	std::shared_ptr<CRing> GetRing() const { return mRing; }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRingTower(this); }

	void InitializeWeapon() override;

	void AddWeapon() override;

private:

	std::shared_ptr<CRing> mRing;		///< CRing object owned by tower

};

