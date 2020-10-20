/**
 * \file Weapon.h
 *
 * \author Zach Arnold
 *
 * Base Class for all weapons, derived from CItem
 */

#pragma once
#include "Item.h"
class CWeapon :
    public CItem
{
public:
    CWeapon(CGame* game);

    /**
    * getter for mDamage
    * \return the damage this weapon deals
    */
    int GetDamage() { return mDamage; }

private:
    int mDamage = 1; //<the damage the weapon deals
};

