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

    /** Getter function for mWidth member
     * \return double representing explosion width
     */
    double GetWidth() const { return mWidth; }

private:

    double mWidth = 120;        ///< Width of explosion lines
};

