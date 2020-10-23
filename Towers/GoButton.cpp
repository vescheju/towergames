#include "pch.h"
#include "GoButton.h"
#include "Game.h"


/**
 * Constructor
 * \param game The game this item is a member of
 */
CGoButton::CGoButton(CGame* game) : CItem(game)
{
	SetImagePtr(mGame->GetImage(L"button-go.png"));
}


/**
 * Destructor
 */
CGoButton::~CGoButton()
{
}

/**
* Set's location of the Go button
* \param x X coordinate to set the button
* \param y Y coordinate to set the button
 */
void CGoButton::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
}