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
 * Update function, if explosion has been detonated, subtract time from mTimeDetonated
 * \param elapsed Time since the class call
 */
void CExplosion::Update(double elapsed)
{
	if (mDetonated)
	{
		mTimeDetonated -= elapsed;
	}
}

/**
* Draw overide function
* \param graphics the graphics to draw items into game
*/
void CExplosion::Draw(Gdiplus::Graphics* graphics)
{
	if (mDetonated)
	{
		SolidBrush brush(Color(128, 0, 0));
		graphics->FillEllipse(&brush, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
			(Gdiplus::REAL)mRadius * 2, (Gdiplus::REAL)mRadius * 2);
		Pen pen(Color(128, 0, 0), 3);
		graphics->DrawEllipse(&pen, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
			(Gdiplus::REAL)mRadius * 2, (Gdiplus::REAL)mRadius * 2);
	}
}


