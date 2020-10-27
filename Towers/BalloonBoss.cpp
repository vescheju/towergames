/**
 * \file BalloonBoss.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "BalloonBoss.h"
#include "BalloonRed.h"
#include "Game.h"
#include "ItemFog.h"

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
	for (int i = 0; i < mNumBalloons; ++i)
	{
		//initial heading of the ballon
		wstring heading = L"E";

		// create the balloon
		shared_ptr<CBalloonRed> balloon = make_shared<CBalloonRed>(mGame, GetRoad(), heading);
		// set the image of the balloon
		balloon->SetImagePtr(mGame->GetImage(L"black-balloon.png"));
		// set the location of the balloon
		balloon->SetLocation(GetX() + pow(-1, i) * mTileLength/4 * ((i+1)%2), GetY());
		balloon->SetHealth(3);
		balloon->SetSpeed(80);
		// add the balloons to the vector
		mBalloons.push_back(balloon);
	}

	mFog = make_shared<CItemFog>(mGame);
	mFog->SetImagePtr(mGame->GetImage(L"fog.png"));
	mFog->SetLocation(-612, 512);
	mFog->SetInitialLocation(mFog->GetX(), mFog->GetY());
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
	if (mFog->GetX() < 516 && mGame->GetButtonPressed())
	{
		mFog->SetLocation(mFog->GetX() + 20 * elapsed, mFog->GetY());
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
	mGame->Add(mFog);
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


/**
 * Draws the Boss balloon and related images
 * \param graphics graphics context to draw to
 */
void CBalloonBoss::Draw(Graphics* graphics)
{
	mFog->Draw(graphics);
	CItem::Draw(graphics);
}