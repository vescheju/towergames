/**
 * \file Dart.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "Dart.h"

 /// towerEight filename
const std::wstring dartFileName = L"images/dart.png";

/// Constant to covert radians to degrees.
const double RtoD = 57.2957795;


/**
 * Constructor
 * \param game The game this item is a member of
 */
CDart::CDart(CGame* game) : CItem(game)
{
	SetImage(dartFileName);
}


/**
 * Destructor
 */
CDart::~CDart()
{
}


/**
 * Draw the rotated dart. Rotation is determined by the member
 * variable mAngle, which is the rotation in radians.
 *
 * @param graphics The graphics context to draw on.
 * @param offsetX An X offset added to the position of the dart.
 * @param offsetY A Y offset added to the position of the dart.
 */

/*
void CDart::Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY)
{
    int wid = CItem::GetImage()->GetWidth();
    int hit = CItem::GetImage()->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((REAL)(GetX() + offsetX),
        (REAL)(GetY() + offsetY));
    graphics->RotateTransform((REAL)(mAngle * RtoD));
    graphics->DrawImage(CItem::GetImage().get(), 0, 0, wid, hit);
    graphics->Restore(save);
}
*/