/**
 * \file TileLocker.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "TileLocker.h"
#include "ItemOpen.h"
#include "RedBombTower.h"
#include "PumpkinTower.h"
#include "RingTower.h"
#include "TowerEight.h"


/// Distance in pixels for tower to lock to open tile
const double LockThreshold = 35;


/**
* Visit a CItemOpen object and add to mOpenTiles
* \param open ItemOpen visiting
*/
void CTileLocker::VisitOpen(CItemOpen* open)
{
	if (open->GetTower() == nullptr)
	{
		mOpenTiles.push_back(open);
	}
}



/**
* Visit a CRedBombTower object and set mTower
* \param bomb BombTower visiting
*/
void CTileLocker::VisitRedBombTower(CRedBombTower* bomb)
{
	mTower = bomb;
}


/**
* Visit a CPumpkinTower object and set mTower
* \param bomb BombTower visiting
*/
void CTileLocker::VisitPumpkinTower(CPumpkinTower* bomb)
{
	mTower = bomb;
}


/**
* Visit a CRingTower object and set mIsTower true
* \param tower RingTower visiting
*/
void CTileLocker::VisitRingTower(CRingTower* tower)
{
	mTower = tower;
}


/**
* Visit a CTowerEight object and set mIsTower true
* \param tower TowerEight visiting
*/
void CTileLocker::VisitTowerEight(CTowerEight* tower)
{
	mTower = tower;
}


/**
* Lock tower to tile thats within a specific proximity
* Uses visited tiles and tower
*/
void CTileLocker::LockTower()
{
	double grabbedX = mTower->GetX();
	double grabbedY = mTower->GetY();
	for (auto tile : mOpenTiles)
	{
		double tileX = tile->GetX();
		double tileY = tile->GetY();

		double distance = sqrt((grabbedX - tileX) * (grabbedX - tileX)
			+ (grabbedY - tileY) * (grabbedY - tileY));

		if (distance < LockThreshold)
		{
			tile->SetTower(mTower);
			mTower->SetLocation(tileX, tileY);
			mTower->SetTile(tile);
		}
	}
}
