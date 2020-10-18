/**
 * \file Dart.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "Dart.h"

 /// towerEight filename
const std::wstring DartFileName = L"images/dart.png";


/**
 * Constructor
 * \param game The game this item is a member of
 * \param angle Int value of angle to set dart at
 */
CDart::CDart(CGame* game, int angle) : CItem(game)
{
	SetImage(DartFileName);
    mAngle = angle;
}


/**
 * Destructor
 */
CDart::~CDart()
{
}


/**
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CDart::Draw(Gdiplus::Graphics* graphics)
{
    int wid = CItem::GetImage()->GetWidth();
    int hit = CItem::GetImage()->GetHeight();
    auto save = graphics->Save();
    graphics->TranslateTransform((Gdiplus::REAL)GetX(),
        (Gdiplus::REAL)GetY());
    graphics->RotateTransform((Gdiplus::REAL)(mAngle));
    graphics->DrawImage(CItem::GetImage().get(), 0, 0, wid, hit);
    graphics->Restore(save);
}
