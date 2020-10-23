/**
 * \file GoVisitor.cpp
 *
 * \author Zach Arnold
 */

#include "pch.h"
#include "GoVisitor.h"
#include "BombTower.h"


/**
* Visit a CBombTower object and set its
* detonation time
* \param bomb BombTower we're visiting
*/
void CGoVisitor::VisitBombTower(CBombTower* bomb)
{
	bomb->SetTimeTillFire(mDetonateTime);
	mDetonateTime += 3;
}
