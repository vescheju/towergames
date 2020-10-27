/**
 * \file GoVisitor.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "GoVisitor.h"
#include "BombTower.h"
#include "TowerEight.h"
#include "RingTower.h"



/**
* Visit a CBombTower object and initializes weapon
* and set its detonation time
* \param bomb BombTower we're visiting
*/
void CGoVisitor::VisitBombTower(CBombTower* bomb)
{
	bomb->InitializeWeapon();
	bomb->SetTimeTillFire(mDetonateTime);
	mDetonateTime += 3;
	mTowers.push_back(bomb);
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

