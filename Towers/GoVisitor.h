/**
 * \file GoVisitor.h
 *
 * \author Zach Arnold
 *
 * Visitor that initializes bomb detonation times
 * once Go button is pressed
 */

#pragma once

#include "ItemVisitor.h"


 /**
  * Sets bomb detonation times
  */
class CGoVisitor :
    public CItemVisitor
{
public:

    virtual void VisitBombTower(CBombTower* bomb) override;

private:

    double mDetonateTime = 3;           ///< Time until detonate for bomb visited

};

