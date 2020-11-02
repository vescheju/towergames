/**
 * \file RedExplosion.h
 *
 * \author Zach Arnold
 *
 * Class represents explosion given by CRedBombTower
 */

#pragma once
#include "Explosion.h"


/**
* A class that implements a red explosion
*/
class CRedExplosion :
    public CExplosion
{
public:
    CRedExplosion(CGame* game);

    /// Copy consturctor (disbabled)
    CRedExplosion(const CExplosion&) = delete;

    /// constructor disabled
    CRedExplosion() = delete;

    void Draw(Gdiplus::Graphics* graphics) override;

    /** Getter function for mRadius member
     * \return double representing radius
     */
    double GetRadius() const { return mRadius; }

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitRedExplosion(this); }

private:

    double mRadius = 100;       ///< radius of circle in pixels
};

