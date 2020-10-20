#include "pch.h"
#include "GoButton.h"
#include "Game.h"

/// Go button filename
const std::wstring GoButtonFileName = L"images/button-go.png";

/**
 * Constructor
 * \param game The game this item is a member of
 */
CGoButton::CGoButton(CGame* game) : CItem(game)
{
	SetImage(GoButtonFileName);
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