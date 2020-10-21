/**
 * \file ItemRemover.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "ItemRemover.h"
#include "Explosion.h"
#include "BombTower.h"
#include "BalloonRed.h"


/**
 * adds red balloons to a vector of they need to be removed
 * \param balloon the balloon being visited
 */
void CItemRemover::VisitBalloonRed(CBalloonRed* balloon)
{
	if (balloon->GetHealth() <= 0 || balloon->GetRoad() == nullptr)
	{
		mRemovedItems.push_back(balloon);
	}
}


/**
 * adds explosions to a vector of they need to be removed
 * \param explosion the explosion being visited
 */
void CItemRemover::VisitExplosion(CExplosion* explosion)
{
	if (explosion->GetTimeDetonated() <= 0)
	{
		mRemovedItems.push_back(explosion);
	}
}


/**
 * adds bombs to a vector of they need to be removed
 * \param bomb the bomb being visited
 */
void CItemRemover::VisitBombTower(CBombTower* bomb)
{
	if (bomb->IsDetonated())
	{
		mRemovedItems.push_back(bomb);
	}
}
