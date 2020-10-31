/**
 * \file Explosion.h
 *
 * \author Zach Arnold
 *
 * Abstract class represents explosion
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

    /** Sets mDetonated to true
     */
    void Detonate() { mDetonated = true; }

    /** Getter function for mDetonated member
     * \return bool representing whether or not explosions been detonated
     */
    bool IsDetonated() const { return mDetonated; }
 
    /** Getter function for mTimeDetonated member
     * \return double representing time left detonated
     */
    double GetTimeDetonated() const { return mTimeDetonated; }

private:
    bool mDetonated = false;        ///< Whether or not explosion has already been detonated

    double mTimeDetonated = 0.25;     ///< Time to stay detonated in seconds
};

