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
	mRing = ring;
	game->Add(ring);
}


/**
 * Update function, shoots ring out if Fire attribute is true
 * \param elapsed Time since the class call
 */
void CRingTower::Update(double elapsed)
{
	if (mRing->GetX() < 1024)
	{
		// Update time till firing
		UpdateTimeTillFire(elapsed);
		if (GetFire())
		{
			// Change radius of ring
			mRing->SetRadius(mRing->GetRadius() + elapsed * RingSpeed);
			if (mRing->GetRadius() > 100)
			{
				// Reset fire and radius attributes if radius > 100
				SetFire(false);
				mRing->SetRadius(10);
			}
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
