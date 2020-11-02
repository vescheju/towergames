/**
 * \file RedExplosion.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "RedExplosion.h"

using namespace Gdiplus;

/**
* explosion consturctor
* \param game the whole game
*/
CRedExplosion::CRedExplosion(CGame* game) : CExplosion(game)
{
}

/**
* Draw overide function
* \param graphics the graphics to draw items into game
*/
void CRedExplosion::Draw(Gdiplus::Graphics* graphics)
{
	if (IsDetonated())
	{
		SolidBrush brush(Color(128, 0, 0));
		graphics->FillEllipse(&brush, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
			(Gdiplus::REAL)mRadius * 2, (Gdiplus::REAL)mRadius * 2);
		Pen pen(Color(128, 0, 0), 3);
		graphics->DrawEllipse(&pen, (Gdiplus::REAL)(GetX() - mRadius), (Gdiplus::REAL)(GetY() - mRadius),
			(Gdiplus::REAL)mRadius * 2, (Gdiplus::REAL)mRadius * 2);
	}
}
