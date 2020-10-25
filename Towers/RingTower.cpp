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


/// Speed in pixels per second for darts to travel
const double RingSpeed = 200;

/**
* Ring Tower constructor
* \param game the whole game
*/
CRingTower::CRingTower(CGame* game) :
	CTower(game)
{
	SetImagePtr(mGame->GetImage(L"tower-rings.png"));
}


/**
 * Update function, shoots ring out if Fire attribute is true
 * \param elapsed Time since the class call
 */
void CRingTower::Update(double elapsed)
{
	if (mGame->GetButtonPressed())
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
	
}


void CRingTower::InitializeWeapon()
{
	std::shared_ptr<CRing> ring(new CRing(mGame));
	ring->SetLocation(GetX(), GetY());
	mRing = ring;
	mGame->Add(ring);
}
