/**
 * \file BalloonBoss.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "BalloonBoss.h"
#include "BalloonRed.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;
 /**
  * Constructor for a red balloon
  *
  * \param game the game that holds everything.
  * \param road the road that the balloon exists on
  * \param heading the initial direction of the road
  */
CBalloonBoss::CBalloonBoss(CGame* game, CItemRoad* road, std::wstring heading) :
	CBalloon(game, road, heading)
{
	
}


/**
 * intiializes the balloons in the boss
 */
void CBalloonBoss::InitializeCariers()
{
	const wstring filename = L"images/black-balloon.png";
	// pointer to the image for all red balloons
	shared_ptr<Gdiplus::Bitmap> itemImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	for (int i = 0; i < mNumBalloons; ++i)
	{
		//initial heading of the ballon
		wstring heading = L"E";

		// create the balloon
		shared_ptr<CBalloonRed> balloon = make_shared<CBalloonRed>(mGame, GetRoad(), heading);
		// set the image of the balloon
		balloon->SetImagePtr(itemImage);
		// set the location of the balloon
		balloon->SetLocation(GetX() + pow(-1, i) * mTileLength/4 * ((i+1)%2), GetY());
		balloon->SetHealth(3);
		balloon->SetSpeed(80);
		// add the balloons to the vector
		mBalloons.push_back(balloon);
	}
}


/**
 * updates all of the balloons in the boss and the boss
 * itself
 * \param elapsed time since last update
 */
void CBalloonBoss::Update(double elapsed)
{
	CBalloon::Update(elapsed);
	for (auto balloon : mBalloons)
	{
		balloon->Update(elapsed);
	}
}


/**
 * triggers the placing of the balloons in the boss
 */
void CBalloonBoss::Pop()
{
	for (auto balloon : mBalloons)
	{
		mGame->Add(balloon);
	}
}


/**
 * adds an active weapon to all of the balloons in the boss
 * and the boss itself
 * \param weapon the weapon to add
 */
void CBalloonBoss::AddActiveWeapon(CWeapon* weapon)
{
	CBalloon::AddActiveWeapon(weapon);
	for (auto balloon : mBalloons)
	{
		balloon->AddActiveWeapon(weapon);
	}
}


/**
 * updates the active weapons by trying to remove one
 * \param weapon the weapon to try and remove
 */
void CBalloonBoss::RemoveActiveWeapon(CWeapon* weapon)
{
	CBalloon::RemoveActiveWeapon(weapon);
	for (auto balloon : mBalloons)
	{
		balloon->RemoveActiveWeapon(weapon);
	}
}