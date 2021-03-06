/**
 * \file ItemHouse.h
 *
 * \author Julius Eillya
 *
 * A class that implements a house item
 */

#pragma once

#include "Item.h"

/**
 * A house item
 */
class CItemHouse : public CItem
{
public:
    CItemHouse(CGame* game);

    ///  Default constructor (disabled)
    CItemHouse() = delete;

    ///  Copy constructor (disabled)
    CItemHouse(const CItemHouse&) = delete;

    ~CItemHouse();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitHouse(this); }
};

