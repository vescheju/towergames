/**
 * \file TileLocker.h
 *
 * \author Zach Arnold
 *
 * Visitor that is used to lock towers to open tiles
 */


#pragma once
#include "ItemVisitor.h"
#include "Item.h"
#include "Tower.h"

#include <vector>
#include <memory>


/**
 * locks together tiles and tower
 */
class CTileLocker :
    public CItemVisitor
{

public:

    virtual void VisitOpen(CItemOpen* open) override;

    virtual void VisitRedBombTower(CRedBombTower* bomb) override;

    virtual void VisitPumpkinTower(CPumpkinTower* bomb) override;

    virtual void VisitRingTower(CRingTower* tower) override;

    virtual void VisitTowerEight(CTowerEight* tower) override;

    void LockTower();

private:

    std::vector<CItemOpen*> mOpenTiles;         ///< vector of open tiles visited

    CTower* mTower = nullptr;           ///< pointer to tower visited
};

