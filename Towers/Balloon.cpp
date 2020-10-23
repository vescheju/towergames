/**
 * \file Balloon.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include "Balloon.h"
#include "Game.h"
#include "BalloonBoss.h"
#include "BalloonRed.h"
#include "Ring.h"


using namespace std;

/// Division constant for Degrees to Radians
const double DtoR = 57.2957795;

/**
 * Constructor for a balloon
 *
 * \param game the game that holds everything.
 * \param road the road that the balloon exists on
 * \param heading the initial direction of the road
 */
CBalloon::CBalloon(CGame* game, CItemRoad* road, std::wstring heading) : CItem(game)
{
	mRoad = road;
	mHeading = heading;
}

/**
* Helper Function to update only the location of the Balloon
* 
* \param elapsed the time since the last update function call
*/
void CBalloon::UpdateLocation(double elapsed)
{
	int newX;
	int newY;
	if (mHeading == L"N")
	{
		newX = GetX();
		newY = GetY() - mSpeed * elapsed;

		// make sure the ballon is centered on the y-axis of the road
		// add any excess location to the y direction
		if (mRoad != nullptr && newX != mRoad->GetX())
		{
			newY -= abs(newX - mRoad->GetX());
			newX = mRoad->GetX();
		}

		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (mRoad != nullptr && newY < mRoad->GetY()- mTileLength / 2)
		{
			mRoad = mRoad->GetNeighbor(L"N");
		}
	}
	else if (mHeading == L"S")
	{
		newX = GetX();
		newY = GetY() + mSpeed * elapsed;
		// make sure the ballon is centered on the y-axis of the road
		// add any excess location to the y direction
		if (mRoad != nullptr && newX != mRoad->GetX())
		{
			newY += abs(newX - mRoad->GetX());
			newX = mRoad->GetX();
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (mRoad != nullptr && newY > mRoad->GetY() + mTileLength/2)
		{
			mRoad = mRoad->GetNeighbor(L"S");
		}
	}
	else if (mHeading == L"E")
	{
		newX = GetX() + mSpeed * elapsed;
		newY = GetY();
		// make sure the ballon is centered on the x-axis of the road
		// add any excess location to the x direction
		if (mRoad != nullptr && newX != mRoad->GetY())
		{
			newX += abs(newY - mRoad->GetY());
			newY = mRoad->GetY();
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (mRoad != nullptr && newX > mRoad->GetX()+ mTileLength/2)
		{
			mRoad = mRoad->GetNeighbor(L"E");
		}
	}
	else if (mHeading == L"W")
	{
		newX = GetX() - mSpeed * elapsed;
		newY = GetY();
		// make sure the ballon is centered on the x-axis of the road
		// add any excess location to the X direction
		if (mRoad != nullptr && newX != mRoad->GetY())
		{
			newX -= abs(newY - mRoad->GetY());
			newY = mRoad->GetY();
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (mRoad != nullptr && newX < mRoad->GetX()- mTileLength / 2)
		{
			mRoad = mRoad->GetNeighbor(L"W");
		}
	}
}



/**
 * Updates the heading of the balloon based off of the road tile 
 * that it is on
 */
void CBalloon::UpdateHeading()
{
	// make sure there is a road that the balloon is on
	if (mRoad != nullptr)
	{
		// update the heading of the balloon based off of the directions of the road
		if (mHeading == L"N" && GetY() <= mRoad->GetY())
		{
			if (mRoad->GetRoadDirection() == L"SW") mHeading = L"W";
			else if (mRoad->GetRoadDirection() == L"SE") mHeading = L"E";
		}
		else if (mHeading == L"S" && GetY() >= mRoad->GetY())
		{
			if (mRoad->GetRoadDirection() == L"NE") mHeading = L"E";
			else if (mRoad->GetRoadDirection() == L"NW") mHeading = L"W";
		}
		else if (mHeading == L"E" && GetX() >= mRoad->GetX())
		{
			if (mRoad->GetRoadDirection() == L"NW") mHeading = L"N";
			else if (mRoad->GetRoadDirection() == L"SW") mHeading = L"S";
		}
		else if (mHeading == L"W" && GetX() <= mRoad->GetX())
		{
			if (mRoad->GetRoadDirection() == L"NE") mHeading = L"N";
			else if (mRoad->GetRoadDirection() == L"SE") mHeading = L"S";
		}
	}
	
}

/**
* Updates the information in the balloon based off of 
* the elapsed time
* 
* \param elapsed the time since the last update function call
*/
void CBalloon::Update(double elapsed)
{
	if (mGame->GetButtonPressed())
	{
		UpdateLocation(elapsed);
		UpdateHeading();
	}
	
}


/**
 * checks if the weapon is already hitting the balloon or not
 * 
 * \param weapon the weapon to check
 * \returns true is it is already being hit by that weapon
 */
bool CBalloon::IsActiveWeapon(CWeapon* weapon)
{
	// iterate through the active weapons on this balloon
	for (CWeapon* activeWeapon : mActiveWeapons)
	{
		if (activeWeapon == weapon)
		{
			return true;
		}
	}
	return false;
}


/**
 * adds weapons that are hitting it to the active weapons
 * \param weapon the weapon to add
 */
void CBalloon::AddActiveWeapon(CWeapon* weapon)
{
	if (!IsActiveWeapon(weapon))
	{
		mActiveWeapons.push_back(weapon);
	}
}


/**
 * remove weapons from the balloon that are no longer hitting it
 * \param weapon the weapon to try and remove
 */
void CBalloon::RemoveActiveWeapon(CWeapon* weapon)
{
	// make sure it is in the list
	if (IsActiveWeapon(weapon))
	{
		//iterate through the list
		for (int i = 0; i < static_cast<int>(mActiveWeapons.size()); ++i)
		{
			// remove it at the correct location from the vector
			if (weapon == mActiveWeapons[i])
			{
				mActiveWeapons.erase(mActiveWeapons.begin() + i);
			}
		}
	}
}


/**
 * checks if any point of the ring is hitting the balloon
 * \param ring the ring to check
 * \returns true if the ring is intercting the balloon
 */
bool CBalloon::IsInterectingRing(CRing* ring)
{
	double ringRadius = ring->GetRadius();
	for (int i = 0; i < 360; ++i)
	{
		double x = ring->GetX() + cos(i / DtoR) * ringRadius;
		double y = ring->GetY() + sin(i / DtoR) * ringRadius;
		if (HitTest(x, y))
		{
			return true;
		}
	}
	return false;
}