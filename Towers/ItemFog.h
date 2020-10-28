/**
 * \file ItemFog.h
 *
 * \author Ian Masterson
 *
 * Class represents the fog that follows the boss
 */

#pragma once
#include "Item.h"


/**
 * class describes the fog item
 */
class CItemFog :
    public CItem
{
private:

	/// the retreat speed of the fog
	int mRetreatSpeed = 40;

	/// the initial x position of the fog
	double initialX;

	/// the initial y position of the fog
	double initialY;

public:

	/// Default construct disabled
	CItemFog() = delete;

	/// Copy construct disabled
	CItemFog(const CItemFog&) = delete;

	CItemFog(CGame* game);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitFog(this); }

	virtual void Update(double elapsed) override;

	/**
	* Sets the location the the fog started at
	* \param x the x position
	* \param y the y position
	*/
	void SetInitialLocation(double x, double y) { initialX = x, initialY = y; }

	/**
	* Getter for the initialX
	* 
	* \return intial x position
	*/
	double GetInitialX() { return initialX; }

	/**
	* Getter for the initialY
	*
	* \return intial y position
	*/
	double GetInitialY() { return initialY; }
};

