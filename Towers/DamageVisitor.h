/**
 * \file DamageVisitor.h
 *
 * \author Ian Masterson
 *
 * Visitor that deals damage to balloons based off of their 
 * position and the weapons position
 */

#pragma once
#include "ItemVisitor.h"
#include "Balloon.h"
#include "BalloonRed.h"
#include "BalloonBoss.h"
#include <vector>


/**
 * collects balloons and items and deals damage 
 */
class CDamageVisitor :
    public CItemVisitor
{
private:
    /// vector containing the level's balloons
    std::vector<CBalloon*> mLevelBalloons;
    /// vector containing the level's darts
    std::vector<CDart*> mLevelDarts;
    /// vector containing the level's rings
    std::vector<CRing*> mLevelRings;
    /// vector containing the level's explosions
    std::vector<CExplosion*> mLevelExplosions;
public:

    virtual void VisitBalloonRed(CBalloonRed* balloon) override;

    virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;

    virtual void VisitDart(CDart* dart) override;

    virtual void VisitRing(CRing* ring) override;

    virtual void VisitExplosion(CExplosion* explosion) override;

    virtual void DealDamage();
};

