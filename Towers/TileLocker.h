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

#include <vector>
#include <memory>


class CTileLocker :
    public CItemVisitor
{

public:

    virtual void VisitOpen(CItemOpen* open) override;

    CItemOpen* LockTower(std::shared_ptr<CItem> tower);

private:

    std::vector<CItemOpen*> mOpenTiles;
};

