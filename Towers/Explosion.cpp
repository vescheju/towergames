/**
 * \file Explosion.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include "Explosion.h"

using namespace Gdiplus;

/**
* explosion consturctor
* \param game the whole game
*/
CExplosion::CExplosion(CGame* game) : CWeapon(game)
{
}


/**
* Draw overide function
* \param graphics the graphics to draw items into game
*/
void CExplosion::Draw(Gdiplus::Graphics* graphics)
{
	SolidBrush brush(Color(128, 0, 0));
	graphics->FillEllipse(&brush, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
		mRadius * 2, mRadius * 2);
	Pen pen(Color(128, 0, 0), 3);
	graphics->DrawEllipse(&pen, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
		mRadius * 2, mRadius * 2);

}


