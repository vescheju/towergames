/**
 * \file Dart.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "Dart.h"
#include "Game.h"



/**
 * Constructor
 * \param game The game this item is a member of
 * \param angle Int value of angle to set dart at
 */
CDart::CDart(CGame* game, int angle) : CWeapon(game)
{
	SetImagePtr(mGame->GetImage(L"dart.png"));
    mAngle = angle;
}


/**
 * Destructor
 */
CDart::~CDart()
{
}


/**
 * Draw our dart
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
