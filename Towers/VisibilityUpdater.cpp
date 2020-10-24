/**
 * \file VisibilityUpdater.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "VisibilityUpdater.h"
#include "BalloonRed.h"
#include "BalloonBoss.h"

using namespace std;


/**
 * visit a red balloon
 * \param balloon the balloon we are visiting
 */
void CVisibilityUpdater::VisitBalloonRed(CBalloonRed* balloon)
{
	mBalloons.push_back(balloon);
}

/**
 * visit a boss balloon
 * \param balloon the balloon we are visiting
 */
void CVisibilityUpdater::VisitBalloonBoss(CBalloonBoss* balloon)
{
	mFog = &(*balloon->GetFog());
}


/**
 * visit a fog object
 * \param fog the fog we are visiting
 */
void CVisibilityUpdater::VisitFog(CItemFog* fog)
{
	mFog = fog;
}


/**
 * updates the visibility of the balloons
 */
void CVisibilityUpdater::UpdateVisibility()
{
	for (auto balloon : mBalloons)
	{
		if (mFog->HitTest(balloon->GetX(), balloon->GetY()) || balloon->GetX() < 0)
		{
			balloon->SetVisibility(false);
		}
		else
		{
			balloon->SetVisibility(true);
		}
	}
}
