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
#include "BalloonBoss.h"
#include "TowerEight.h"
#include "RingTower.h"
#include "RedBombTower.h"
#include "PumpkinTower.h"

/**
 * adds red balloons to a vector of they need to be removed
 * \param balloon the balloon being visited
 */
void CItemRemover::VisitBalloonRed(CBalloonRed* balloon)
{
	if (balloon->GetHealth() <= 0)
	{
		mRemovedItems.push_back(balloon);
	}
	else if (balloon->GetRoad() == nullptr)
	{
		mRemovedItems.push_back(balloon);
		mScoreChange -= 1;
	}
}

/**
 * adds boss balloons to a vector of they need to be removed
 * \param balloon the balloon being visited
 */
void CItemRemover::VisitBalloonBoss(CBalloonBoss* balloon)
{
	if (balloon->GetRoad() == nullptr)
	{
		balloon->Pop();
		mRemovedItems.push_back(balloon);
		mScoreChange -= 5;
	}
	else if (balloon->GetHealth() <= 0)
	{
		balloon->Pop();
		mRemovedItems.push_back(balloon);
	}
}

void CItemRemover::VisitTowerEight(CTowerEight* tower)
{
	if (tower->GetTile() == nullptr && !tower->Grabbed())
	{
		mRemovedItems.push_back(tower);
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




void CItemRemover::VisitRingTower(CRingTower* tower)
{
	if (tower->GetTile() == nullptr && !tower->Grabbed())
	{
		mRemovedItems.push_back(tower);
	}
}

/**
 * adds bombs to a vector of they need to be removed
 * \param bomb the bomb being visited
 */
void CItemRemover::VisitRedBombTower(CRedBombTower* bomb)
{
	if (bomb->GetTile() == nullptr && !bomb->Grabbed() || bomb->IsDetonated())
	{
		mRemovedItems.push_back(bomb);
	}
}


/**
 * adds pumpkin bombs to a vector of they need to be removed
 * \param bomb the bomb being visited
 */
void CItemRemover::VisitPumpkinTower(CPumpkinTower* bomb)
{
	if (bomb->GetTile() == nullptr && !bomb->Grabbed() || bomb->IsDetonated())
	{
		mRemovedItems.push_back(bomb);
	}
}


/**
* adds the fog to the removed items list if its 
* x position is less than the inital x
* 
* \param fog the fog item to visit
*/
void CItemRemover::VisitFog(CItemFog* fog)
{
	if (fog->GetX() <= fog->GetInitialX())
	{
		mRemovedItems.push_back(fog);
	}
}
