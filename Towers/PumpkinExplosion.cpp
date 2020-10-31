/**
 * \file PumpkinExplosion.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "PumpkinExplosion.h"

using namespace Gdiplus;

CPumpkinExplosion::CPumpkinExplosion(CGame* game) : CExplosion(game)
{
}

/**
* Draw overide function
* \param graphics the graphics to draw items into game
*/
void CPumpkinExplosion::Draw(Gdiplus::Graphics* graphics)
{
	if (IsDetonated())
	{
		SolidBrush brush(Color(255, 128, 0));
		graphics->FillEllipse(&brush, (Gdiplus::REAL)(GetX() - mWidth), (Gdiplus::REAL)(GetY() - mWidth),
			(Gdiplus::REAL)mWidth * 2, (Gdiplus::REAL)mWidth * 2);
		Pen pen(Color(255, 128, 0), 3);
		graphics->DrawEllipse(&pen, (Gdiplus::REAL)(GetX() - mWidth), (Gdiplus::REAL)(GetY() - mWidth),
			(Gdiplus::REAL)mWidth * 2, (Gdiplus::REAL)mWidth * 2);
	}
}
