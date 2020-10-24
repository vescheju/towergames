/**
 * \file BalloonRed.h
 *
 * \author Justin Vesche
 *
 * Class that creates a red balloon
 *
 * This class creates the basic red balloon
 * for the game.
 */

#pragma once
#include "Balloon.h"

/**
 * Base class for a red balloon
 * 
 * This applies to all of the red balloon
 * items in the game.
 */
class CBalloonRed : public CBalloon
{
public:

	CBalloonRed(CGame* game, CItemRoad * road, std::wstring heading);

	/// Default constructor (disabled)
	CBalloonRed() = delete;

	/// Copy consturctor (disbabled)
	CBalloonRed(const CBalloonRed&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloonRed(this); }

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* getter for visiblity
	* \return if the balloon should be drawn or not
	*/
	bool IsVisible() { return mVisible; }

	/**
	* setter for the visibility
	* \param visibility the visibility to set
	*/
	void SetVisibility(bool visibility) { mVisible = visibility; }

private:
	/// keeps track of drawing the balloon or not
	bool mVisible = false;
};

