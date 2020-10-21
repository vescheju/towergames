/**
 * \file Explosion.h
 *
 * \author Zach Arnold
 *
 * Class represents explosion given by CBombTower
 */
#pragma once
#include "Weapon.h"
class CExplosion :
    public CWeapon
{
public:
    CExplosion(CGame* game);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitExplosion(this); }

    /** Getter function for mRadius member
     * \return double representing radius
     */
    double GetRadius() const { return mRadius; }

    void Draw(Gdiplus::Graphics* graphics) override;

    /// Copy consturctor (disbabled)
    CExplosion(const CExplosion&) = delete;

    /// constructor disabled
    CExplosion() = delete;

    /** Getter function for mMaxRadius member
     * \return double representing max radius
     */
    double GetMaxRadius() const { return mMaxRadius; }

private:
    /// radius of circle in pixels
    double mRadius = 10;
    double mMaxRadius = 100;
};

