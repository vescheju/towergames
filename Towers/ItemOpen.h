/**
 * \file ItemOpen.h
 *
 * \author Julius Eillya
 *
 * A class to represent an open spot in our game
 */

#pragma once
#include "Item.h"

class CTower;

/**
 * An open spot for any item
 */
class CItemOpen : public CItem
{

public:
    CItemOpen(CGame* game);

    ///  Default constructor (disabled)
    CItemOpen() = delete;

    ///  Copy constructor (disabled)
    CItemOpen(const CItemOpen&) = delete;

    ~CItemOpen();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitOpen(this); }

    /** Set mTower to value
    * \param tower CTower object to set mTower to
    */
    void SetTower(CTower* tower) { mTower = tower; }

    /** Get mTower value
    * \return CTower object
    */
    CTower* GetTower() const { return mTower; }

private:

    CTower* mTower = nullptr;           ///< Tower sitting on this open location
};

