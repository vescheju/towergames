/**
 * \file GrabVisitor.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "GrabVisitor.h"
#include "BombTower.h"
#include "TowerEight.h"
#include "RingTower.h"


/**
* Visit a CBombTower object and add to mTowers
* \param bomb BombTower visiting
*/
void CGrabVisitor::VisitBombTower(CBombTower* bomb)
{
	mTowers.push_back(bomb);
}


/**
* Visit a CTowerEight object and add to mTowers
* \param tower TowerEight visiting
*/
void CGrabVisitor::VisitTowerEight(CTowerEight* tower)
{
	mTowers.push_back(tower);
}


/**
* Visit a CRingTower object and add to mTowers
* \param tower RingTower visiting
*/
void CGrabVisitor::VisitRingTower(CRingTower* tower)
{
	mTowers.push_back(tower);
}


