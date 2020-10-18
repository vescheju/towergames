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

};

