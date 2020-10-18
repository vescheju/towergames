/**
 * \file GoButton.h
 *
 * \author Julius Eillya
 *
 * A class that implements a Go button
 */

#pragma once

#include "Item.h"


/**
 * The class for the game's Go button
 */
class CGoButton : public CItem
{
public:
	/// Constructor
	CGoButton(CGame* game);

	/// Default constructor (disabled)
	CGoButton() = delete;

	/// Copy constructor (disabled)
	CGoButton(const CGoButton&) = delete;

	~CGoButton();

	void SetLocation(double x, double y) override;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitGoButton(this); }
};

