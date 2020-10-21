/**
 * \file RingTower.cpp
 *
 * \author Zach Arnold
 */
#include "pch.h"
#include "TowerEight.h"
#include "Dart.h"
#include "Game.h"
#include <string>

/// TowerEight filename
const std::wstring TowerEightName = L"images/tower8.png";

/// Division constant for Degrees to Radians
const double DtoR = 57.2957795;

/// Speed in pixels per second for darts to travel
const double DartSpeed = 200;


/**
* TowerEight Constructor
* \param game the whole game
*/
CTowerEight::CTowerEight(CGame* game) :
	CTower(game)
{
	SetImage(TowerEightName);
	for (int a = 0; a < 360; a += 45)
	{
		std::shared_ptr<CDart> dart(new CDart(game, a));
		mDarts.push_back(dart);
		game->Add(dart);
	}
}


/**
 * Update function, shoots darts out if Fire attribute is true
 * \param elapsed Time since the class call
 */
void CTowerEight::Update(double elapsed)
{
	if (mDarts[0]->GetX() < 1024)
	{
		// Update time till firing
		UpdateTimeTillFire(elapsed);
		// if currently firing
		if (GetFire())
		{
			// calculate new position of each dart
			for (auto dart : mDarts)
			{
				double a = dart->GetAngle() / DtoR;
				double sn = sin(a);
				double cs = cos(a);

				double x = GetX() + cs * mT;
				double y = GetY() + sn * mT;
				dart->SetLocation(x, y);
			}
			mT += elapsed * DartSpeed;
			// if distance passed 100 pixels from tower
			if (mT > 100)
			{
				// reset fire and mT attributes and dart locations
				SetFire(false);
				mT = 10;
				for (auto dart : mDarts)
				{
					dart->SetLocation(GetX(), GetY());
				}
			}
		}
	}
}


/**
* Set's location of Tower and its Darts
* \param x X coordinate to set Tower and Darts at
* \param y Y coordinate to set Tower and Darts at
 */
void CTowerEight::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	// set locations of darts with tower
	for (auto dart : mDarts)
	{
		dart->SetLocation(x, y);
	}
}

