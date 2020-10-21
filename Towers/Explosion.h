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

    void Update(double elapsed);

    /// Copy consturctor (disbabled)
    CExplosion(const CExplosion&) = delete;

    /// constructor disabled
    CExplosion() = delete;

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitExplosion(this); }

    /** Getter function for mRadius member
     * \return double representing radius
     */
    double GetRadius() const { return mRadius; }

    void Draw(Gdiplus::Graphics* graphics) override;

    void Detonate() { mDetonated = true; }

    bool isDetonated() const { return mDetonated; }

    double GetTimeDetonated() const { return mTimeDetonated; }

private:
    /// radius of circle in pixels
    double mRadius = 100;

    bool mDetonated = false;

    double mTimeDetonated = 0.25;
};

