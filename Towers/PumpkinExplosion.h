/**
 * \file PumpkinExplosion.h
 *
 * \author Zach Arnold
 *
 * Class represents explosion given by CPumpkinTower
 */
#pragma once
#include "Explosion.h"

/**
* A class that implements a pumpkin explosion
*/
class CPumpkinExplosion :
    public CExplosion
{
public:
    CPumpkinExplosion(CGame* game);

    /// Copy consturctor (disbabled)
    CPumpkinExplosion(const CExplosion&) = delete;

    /// constructor disabled
    CPumpkinExplosion() = delete;

    void Draw(Gdiplus::Graphics* graphics) override;

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPumpkinExplosion(this); }

private:

    double mWidth = 100;        ///< Width of explosion lines
};

