/**
 * \file PumpkinExplosion.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "PumpkinExplosion.h"
#include "Game.h"

using namespace Gdiplus;

/**
* explosion consturctor
* \param game the whole game
*/
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
		graphics->FillRectangle(&brush, (Gdiplus::REAL)(GetX() - (mWidth / 2)), (Gdiplus::REAL)0,
			(Gdiplus::REAL)mWidth, (Gdiplus::REAL)mGame->GetGameHeight());
		graphics->FillRectangle(&brush, (Gdiplus::REAL)0, (Gdiplus::REAL)(GetY() - (mWidth / 2)),
			(Gdiplus::REAL)mGame->GetGameWidth(), (Gdiplus::REAL)mWidth);
		Pen pen(Color(255, 128, 0), 3);
		graphics->DrawRectangle(&pen, (Gdiplus::REAL)(GetX() - (mWidth / 2)), (Gdiplus::REAL)0,
			(Gdiplus::REAL)mWidth, (Gdiplus::REAL)mGame->GetGameHeight());
		graphics->DrawRectangle(&pen, (Gdiplus::REAL)0, (Gdiplus::REAL)(GetY() - (mWidth / 2)),
			(Gdiplus::REAL)mGame->GetGameWidth(), (Gdiplus::REAL)mWidth);
	}
}
