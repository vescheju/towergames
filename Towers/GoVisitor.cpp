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
* Visit a CBombTower object and set its
* detonation time
* \param bomb BombTower we're visiting
*/
void CGoVisitor::VisitBombTower(CBombTower* bomb)
{
	bomb->InitializeWeapon();
	bomb->SetTimeTillFire(mDetonateTime);
	mDetonateTime += 3;
}

void CGoVisitor::VisitTowerEight(CTowerEight* tower)
{
	tower->InitializeWeapon();
	mTowers.push_back(tower);
}

void CGoVisitor::VisitRingTower(CRingTower* tower)
{
	tower->InitializeWeapon();
	mTowers.push_back(tower);
}

