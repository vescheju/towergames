#include "pch.h"
#include "TowerEight.h"
#include "Dart.h"
#include "Game.h"
#include <string>

/// TowerEight filename
const std::wstring TowerEightName = L"images/tower8.png";

/// Time between each firing of darts
double TimeBetweenShots = 5;

/// Vector of degrees to assign to darts contained by tower
const std::vector<int> DegreesVector{ 0, 45, 90, 135, 180, 225, 270, 315 };

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
	for (int angle : DegreesVector)
	{
		std::shared_ptr<CDart> dart(new CDart(game, angle));
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
	// calculate time until next fire
	mTimeTillFire -= elapsed;
	if (mTimeTillFire <= 0)
	{
		// if it's time to fire, reset timer and set fire attribute to true
		mTimeTillFire += TimeBetweenShots;
		mFire = true;
	}
	// if currently firing
	if (mFire)
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
			mFire = false;
			mT = 10;
			for (auto dart : mDarts)
			{
				dart->SetLocation(GetX(), GetY());
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

