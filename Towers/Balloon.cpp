/**
 * \file Balloon.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include "Balloon.h"




/**
 * Constructor for balloon
 * 
 * \param game the game that holds everything.
 */
CBalloon::CBalloon(CGame* game) : CItem(game)
{
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
		if (mRoad != nullptr && newX != mRoad->GetX() + mTileLength / 2)
		{
			newX = mRoad->GetX() + mTileLength / 2;
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (newY <= mRoad->GetY())
		{
			mRoad = mRoad->GetNeighbor(L"N");
		}
	}
	else if (mHeading == L"S")
	{
		newX = GetX();
		newY = GetY() + mSpeed * elapsed;
		// make sure the ballon is centered on the y-axis of the road
		if (mRoad != nullptr && newX != mRoad->GetX() + mTileLength / 2)
		{
			newX = mRoad->GetX() + mTileLength / 2;
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (newY >= mRoad->GetY())
		{
			mRoad = mRoad->GetNeighbor(L"S");
		}
	}
	else if (mHeading == L"E")
	{
		newX = GetX() + mSpeed * elapsed;
		newY = GetY();
		// make sure the ballon is centered on the x-axis of the road
		if (mRoad != nullptr && newX != mRoad->GetY() + mTileLength / 2)
		{
			newX = mRoad->GetY() + mTileLength / 2;
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (newY >= mRoad->GetX())
		{
			mRoad = mRoad->GetNeighbor(L"E");
		}
	}
	else if (mHeading == L"W")
	{
		newX = GetX() - mSpeed * elapsed;
		newY = GetY();
		// make sure the ballon is centered on the x-axis of the road
		if (mRoad != nullptr && newX != mRoad->GetY() + mTileLength / 2)
		{
			newX = mRoad->GetY() + mTileLength / 2;
		}
		SetLocation(newX, newY);

		// update the road pointer if the balloon is on a new tile
		if (newY <= mRoad->GetX())
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
		// heading gets updated whenever the ballon reaches the center of the road
		if (GetX() == mRoad->GetX() + mTileLength / 2 &&
			GetY() == mRoad->GetY() + mTileLength / 2)
		{
			// update the heading of the balloon based off of the directions of the road
			if (mHeading == L"N")
			{
				if (mRoad->GetRoadDirection() == L"NE") mHeading == L"E";
				else if (mRoad->GetRoadDirection() == L"NW") mHeading == L"W";
			}
			else if (mHeading == L"S")
			{
				if (mRoad->GetRoadDirection() == L"SE") mHeading == L"E";
				else if (mRoad->GetRoadDirection() == L"SW") mHeading == L"W";
			}
			else if (mHeading == L"E")
			{
				if (mRoad->GetRoadDirection() == L"SE") mHeading == L"S";
				else if (mRoad->GetRoadDirection() == L"NE") mHeading == L"N";
			}
			else if (mHeading == L"W")
			{
				if (mRoad->GetRoadDirection() == L"SW") mHeading == L"S";
				else if (mRoad->GetRoadDirection() == L"NW") mHeading == L"N";
			}

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
	UpdateLocation(elapsed);
	UpdateHeading();
}