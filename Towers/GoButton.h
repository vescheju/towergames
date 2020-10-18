#pragma once

#include "Item.h"

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

