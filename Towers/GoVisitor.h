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
#include<vector>

class CTower;

 /**
  * Sets up towers for use in game
  */
class CGoVisitor :
    public CItemVisitor
{
public:

    virtual void VisitBombTower(CBombTower* bomb) override;

    virtual void VisitTowerEight(CTowerEight* bomb) override;

    virtual void VisitRingTower(CRingTower* bomb) override;

    void AddWeapons();

    /** Getter function returns towers collected by visitor
    * \return vector of Towers
    */
    std::vector<CTower*> GetTowers() const { return mTowers; }

private:

    double mDetonateTime = 3;           ///< Time until detonate for bomb visited

    std::vector<CTower*> mTowers;       ///< Towers collected by visitor

};

