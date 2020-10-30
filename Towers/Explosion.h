/**
 * \file Explosion.h
 *
 * \author Zach Arnold
 *
 * Class represents explosion given by CBombTower
 */
#pragma once
#include "Weapon.h"

/**
 * A class that implements an explosion
 */
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

    /** Sets mDetonated to true
     */
    void Detonate() { mDetonated = true; }

    /** Getter function for mDetonated member
     * \return bool representing whether or not explosions been detonated
     */
    bool isDetonated() const { return mDetonated; }
 
    /** Getter function for mTimeDetonated member
     * \return double representing time left detonated
     */
    double GetTimeDetonated() const { return mTimeDetonated; }

private:
    /// radius of circle in pixels
    double mRadius = 100;

    bool mDetonated = false;        ///< Whether or not explosion has already been detonated

    double mTimeDetonated = 0.25;     ///< Time to stay detonated in seconds
};

