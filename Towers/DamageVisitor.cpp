/**
 * \file DamageVisitor.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "DamageVisitor.h"
#include "BalloonRed.h"
#include "Dart.h"
#include "Ring.h"
#include "Explosion.h"

 /**
 * Visit a CBalloonRed object and add it to the
 * mLevelBalloons vector
 * \param balloon Balloon item we are visiting
 */
void CDamageVisitor::VisitBalloonRed(CBalloonRed* balloon)
{
    mLevelRedBalloons.push_back(balloon);
}

/**
* Visit a CDart object and add it to the
* mLevelDarts vector
* \param dart Dart item we are visiting
*/
void CDamageVisitor::VisitDart(CDart* dart)
{
    mLevelDarts.push_back(dart);
}

/**
* Visit a CRing object and add it to the
* mLevelRings vector
* \param ring Ring item we are visiting
*/
void CDamageVisitor::VisitRing(CRing* ring)
{
    mLevelRings.push_back(ring);
}

/**
* Visit a CExplosion object and add it to the
* mLevelExplosions vector
* \param explosion Explosion item we are visiting
*/
void CDamageVisitor::VisitExplosion(CExplosion* explosion)
{
    mLevelExplosions.push_back(explosion);
}


/**
 * Deals damage to the balloons
 */
void CDamageVisitor::DealDamage()
{
    // iterate through the balloons
    for (auto balloon : mLevelRedBalloons)
    {
        // check darts
        for (auto dart : mLevelDarts)
        {
            if (balloon->ImagesAreOverlapping(dart))
            {
                balloon->Damage(dart->GetDamage());
            }
        }
        // check rings
        for (auto ring : mLevelRings)
        {
            // if the balloon is in the rings area it is getting damage done
            // center of the ring
            double ringX = ring->GetX();
            double ringY = ring->GetY();
            
            // center of the item
            double balloonX = balloon->GetX();
            double balloonY = balloon->GetY();

            // the scalar distance between the centers
            double distance = sqrt((ringX-balloonX) * (ringX - balloonX) - (ringY - balloonY) * (ringY - balloonY));
            
            // if the distance is shorter than the radius then they are hitting
            if (distance <= ring->GetRadius())
            {
                balloon->Damage(ring->GetDamage());
            }
        }

        for (auto explosion : mLevelExplosions)
        {
            // if the balloon is in the explosions area it is getting damage done
            // center of the explosion
            double explosionX = explosion->GetX();
            double explosionY = explosion->GetY();

            // center of the item
            double balloonX = balloon->GetX();
            double balloonY = balloon->GetY();

            // the scalar distance between the centers
            double distance = sqrt((explosionX - balloonX) * (explosionX - balloonX) - (explosionY - balloonY) * (explosionY - balloonY));

            // if the distance is shorter than the radius then they are hitting
            if (distance <= explosion->GetRadius())
            {
                balloon->Damage(explosion->GetDamage());
            }
        }
    }
}