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
};

