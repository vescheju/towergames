/**
 * \file Ring.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "Ring.h"

using namespace Gdiplus;

/**
* Ring Constructor function
*\param game representing the game as a whole
*/
CRing::CRing(CGame* game) : CWeapon(game)
{

}

/**
 * Destructor
 */
CRing::~CRing()
{

}

/**
 * Draw our ring
 * \param graphics The graphics context to draw on
 */
void CRing::Draw(Gdiplus::Graphics* graphics)
{
	Pen pen(Color(255, 0, 0), 3);
	graphics->DrawEllipse(&pen, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
		mRadius * 2, mRadius * 2);
}

