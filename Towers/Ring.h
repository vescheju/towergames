/**
 * \file Ring.h
 *
 * \author Hithesh Yedlapati
 *
 * Class for creating Ring around CRingTower
 */

#pragma once
#include "Weapon.h"

using namespace Gdiplus;

/**
* CRing class creates ring that increases over time
* derived from CItem
*/
class CRing : public CWeapon
{
public:
	/// constructor
	CRing(CGame* game);

	void Draw(Gdiplus::Graphics* graphics) override;

	/// constructor disabled
	CRing() = delete;

	~CRing();

	/// copy constructor
	CRing(const CRing&) = delete;

	/** Setter function for mRadius member
	 * \param fire double to set mRadius to
	 */
	void SetRadius(double radius) { mRadius = radius; }
	
	/** Getter function for mRadius member
	 * \return double representing radius
	 */
	double GetRadius() const { return mRadius; }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRing(this); }

private:
	/// radius or ring, initialized to 10 pixels
	double mRadius = 10;
};

