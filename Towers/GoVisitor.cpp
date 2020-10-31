/**
 * \file GoVisitor.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "GoVisitor.h"
#include "RedBombTower.h"
#include "PumpkinTower.h"
#include "TowerEight.h"
#include "RingTower.h"


/// Time in seconds for pumpkin bomb to detonate
const double PumpkinDetonateTime = 15;

/// Time in seconds for red bomb to detonate in increments
const double RedDetonateTime = 3;


/**
* Visit a CRedBombTower object and initializes weapon
* and set its detonation time
* \param bomb BombTower we're visiting
*/
void CGoVisitor::VisitRedBombTower(CRedBombTower* bomb)
{
	bomb->InitializeWeapon();
	bomb->SetTimeTillFire(mDetonateTime);
	mDetonateTime += RedDetonateTime;
}


/**
* Visit a CPumpkinTower object and initializes weapon
* and set its detonation time
* \param bomb BombTower we're visiting
*/
void CGoVisitor::VisitPumpkinTower(CPumpkinTower* bomb)
{
	bomb->InitializeWeapon();
	bomb->SetTimeTillFire(PumpkinDetonateTime);
}


/**
* Visit a CTowerEight object and initializes weapon
* \param tower TowerEight we're visiting
*/
void CGoVisitor::VisitTowerEight(CTowerEight* tower)
{
	tower->InitializeWeapon();
	mTowers.push_back(tower);
}


/**
* Visit a CRingTower object and initializes weapon
* \param tower RingTower we're visiting
*/
void CGoVisitor::VisitRingTower(CRingTower* tower)
{
	tower->InitializeWeapon();
	mTowers.push_back(tower);
}


/**
 * For tower in mTowers, add its weapon to the game 
 */
void CGoVisitor::AddWeapons()
{
	for (auto tower : mTowers)
	{
		tower->AddWeapon();
	}
}

