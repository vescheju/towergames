/**
 * \file BalloonRed.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "BalloonRed.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor for a red balloon
 *
 * \param game the game that holds everything.
 * \param road the road that the balloon exists on
 * \param heading the initial direction of the road
 */
CBalloonRed::CBalloonRed(CGame* game, CItemRoad* road, std::wstring heading) :
	CBalloon(game, road, heading)
{
}


/**
 * Draw the balloon
 * \param graphics The graphics context to draw on
 */
void CBalloonRed::Draw(Graphics* graphics)
{
    if (GetImage() != nullptr && GetRoad() != nullptr &&
        (GetRoad()->IsLit() || IsVisible()))
    {
        double wid = GetImage()->GetWidth();
        double hit = GetImage()->GetHeight();
        graphics->DrawImage(GetImage().get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)GetImage()->GetWidth() + 1, (float)GetImage()->GetHeight() + 1);
    }
}