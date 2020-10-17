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
CDart::CDart(CGame* game, int angle) : CItem(game)
{
	SetImage(dartFileName);
    mAngle = angle;
}


/**
 * Destructor
 */
CDart::~CDart()
{
}

void CDart::Fire()
{
}

void CDart::Draw(Gdiplus::Graphics* graphics)
{
    Draw(graphics, 100, 100);
}

/**
 * Draw the rotated dart. Rotation is determined by the member
 * variable mAngle, which is the rotation in radians.
 *
 * @param graphics The graphics context to draw on.
 * @param offsetX An X offset added to the position of the dart.
 * @param offsetY A Y offset added to the position of the dart.
 */


void CDart::Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY)
{
    int wid = CItem::GetImage()->GetWidth();
    int hit = CItem::GetImage()->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((Gdiplus::REAL)(GetX() + offsetX),
        (Gdiplus::REAL)(GetY() + offsetY));
    graphics->RotateTransform((Gdiplus::REAL)(mAngle));
    graphics->DrawImage(CItem::GetImage().get(), 0, 0, wid, hit);
    graphics->Restore(save);
}


/*
void CDart::Draw(Gdiplus::Graphics* graphics)
{
    int wid = CItem::GetImage()->GetWidth();
    int hit = CItem::GetImage()->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((Gdiplus::REAL)(GetX()),
        (Gdiplus::REAL)(GetY()));
    graphics->RotateTransform((Gdiplus::REAL)(mAngle));
    graphics->DrawImage(CItem::GetImage().get(), 0, 0, wid, hit);
    graphics->Restore(save);
}
*/
