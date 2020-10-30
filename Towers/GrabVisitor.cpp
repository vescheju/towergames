/**
 * \file GrabVisitor.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "GrabVisitor.h"
#include "RedBombTower.h"
#include "PumpkinTower.h"
#include "TowerEight.h"
#include "RingTower.h"


/**
* Visit a CRedBombTower object and add to mTowers
* \param bomb BombTower visiting
*/
void CGrabVisitor::VisitRedBombTower(CRedBombTower* bomb)
{
	mTowers.push_back(bomb);
}


/**
* Visit a CPumpkinTower object and add to mTowers
* \param bomb BombTower visiting
*/
void CGrabVisitor::VisitPumpkinTower(CPumpkinTower* bomb)
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


