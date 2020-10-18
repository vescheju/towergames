/**
 * \file RingTower.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "RingTower.h"
#include "Ring.h"
#include "Game.h"
#include <string>

 /// Time between each firing of darts
double TimeBetween = 5;

/// ring tower png file
const std::wstring ringTowerName = L"images/tower-rings.png";

/// Speed in pixels per second for darts to travel
const double RingSpeed = 200;

/**
* Ring Tower constructor
* \param game the whole game
*/
CRingTower::CRingTower(CGame* game) :
	CTower(game)
{
	SetImage(ringTowerName);
	std::shared_ptr<CRing> ring(new CRing(game));
	game->Add(ring);
	mRing = ring;
}


/**
 * Update function, shoots ring out if Fire attribute is true
 * \param elapsed Time since the class call
 */
void CRingTower::Update(double elapsed)
{
	// calculate time until next fire
	mTimeTillFire -= elapsed;
	if (mTimeTillFire <= 0)
	{
		// if it's time to fire, reset timer and set fire attribute to true
		mTimeTillFire += TimeBetween;
		mFire = true;
	}
	if (mFire)
	{
		mRing->SetRadius(mRing->GetRadius() + elapsed * RingSpeed);
		if (mRing->GetRadius() > 100)
		{
			mFire = false;
			mRing->SetRadius(10);
		}
	}
}

/**
* Set's location of Tower and its Ring
* \param x X coordinate to set Tower and Ring at
* \param y Y coordinate to set Tower and Ring at
 */
void CRingTower::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	// set locations of ring with tower
	mRing->SetLocation(x, y);
}

