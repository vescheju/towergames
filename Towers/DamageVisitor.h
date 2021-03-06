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
    std::vector<CRedExplosion*> mLevelRedExplosions;
    /// vector containing the level's explosions
    std::vector<CPumpkinExplosion*> mLevelPumpkinExplosions;
    /// the score change as a result of the balloons being damaged
    int mScoreChange = 0;
public:

    virtual void VisitBalloonRed(CBalloonRed* balloon) override;

    virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;

    virtual void VisitDart(CDart* dart) override;

    virtual void VisitRing(CRing* ring) override;

    virtual void VisitRedExplosion(CRedExplosion* explosion) override;

    virtual void VisitPumpkinExplosion(CPumpkinExplosion* explosion) override;

    virtual void DealDamage();

    /**
    * Returns the change of score
    * 
    * \return the score change
    */
    virtual int GetScoreChange() { return mScoreChange; }
};

