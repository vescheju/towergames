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
* Visit a CBombTower object and set mIsTower true
* \param bomb BombTower visiting
*/
void CGrabVisitor::VisitBombTower(CBombTower* bomb)
{
	mIsTower = true;
}


/**
* Visit a CTowerEight object and set mIsTower true
* \param tower TowerEight visiting
*/
void CGrabVisitor::VisitTowerEight(CTowerEight* tower)
{
	mIsTower = true;
}


/**
* Visit a CRingTower object and set mIsTower true
* \param tower RingTower visiting
*/
void CGrabVisitor::VisitRingTower(CRingTower* tower)
{
	mIsTower = true;
}

