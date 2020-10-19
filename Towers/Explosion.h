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
};

