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
#include "RedExplosion.h"
#include "PumpkinExplosion.h"


/// Double representing how much time of detonation must be left for explosion to damage balloon
const double MinTimeDetonatedLeft = 0.245;    

 /**
 * Visit a CBalloonRed object and add it to the
 * mLevelBalloons vector
 * \param balloon Balloon item we are visiting
 */
void CDamageVisitor::VisitBalloonRed(CBalloonRed* balloon)
{
    mLevelBalloons.push_back(balloon);
}

/**
* Visit a CBalloonBoss object and add it to the
* mLevelBalloons vector
* \param balloon Balloon item we are visiting
*/
void CDamageVisitor::VisitBalloonBoss(CBalloonBoss* balloon)
{
    mLevelBalloons.push_back(balloon);
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
* Visit a CRedExplosion object and add it to the
* mLevelRedExplosions vector
* \param explosion Explosion item we are visiting
*/
void CDamageVisitor::VisitRedExplosion(CRedExplosion* explosion)
{
    // Only add explosion if its been detonated for a maximum for 0.005 seconds
    if (explosion->IsDetonated() && explosion->GetTimeDetonated() >= MinTimeDetonatedLeft)
    {
        mLevelRedExplosions.push_back(explosion);
    }
}

/**
* Visit a CPumpkinExplosion object and add it to the
* mLevelPumpkinExplosions vector
* \param explosion Explosion item we are visiting
*/
void CDamageVisitor::VisitPumpkinExplosion(CPumpkinExplosion* explosion)
{
    // Only add explosion if its been detonated for a maximum for 0.005 seconds
    if (explosion->IsDetonated() && explosion->GetTimeDetonated() >= MinTimeDetonatedLeft)
    {
        mLevelPumpkinExplosions.push_back(explosion);
    }
}


/**
 * Deals damage to the balloons
 */
void CDamageVisitor::DealDamage()
{
    // iterate through the balloons
    for (auto balloon : mLevelBalloons)
    {
        // check darts
        for (auto dart : mLevelDarts)
        {
            // if the center of the dart is in the balloon is is being hit
            if (balloon->HitTest(dart->GetX(), dart->GetY()) && !balloon->IsActiveWeapon(dart))
            {
                balloon->Damage(dart->GetDamage());
                balloon->AddActiveWeapon(dart);

                if (balloon->GetHealth() <= 0)
                {
                    mScoreChange += 10;
                }
            }
            else
            {
                balloon->RemoveActiveWeapon(dart);
            }

        }
        // check rings
        for (auto ring : mLevelRings)
        {
            double distance = sqrt((ring->GetX() - balloon->GetX()) * (ring->GetX() - balloon->GetX()) +
                (ring->GetY() - balloon->GetY()) * (ring->GetY() - balloon->GetY()));
            // if the balloon is intersecting the ring then it is getting damage done
            if (ring->GetRadius() > distance) {
                balloon->Damage(ring->GetDamage());
                balloon->AddActiveWeapon(ring);
                if (balloon->GetHealth() <= 0)
                {
                    mScoreChange += 3;
                }
            }
            // if the ring has been reset then remove it from the active weapons
            else
            {
                balloon->RemoveActiveWeapon(ring);
            }
            
        }

        for (auto explosion : mLevelRedExplosions)
        {
            // if the balloon is in the explosions area it is getting damage done
            // center of the explosion
            double explosionX = explosion->GetX();
            double explosionY = explosion->GetY();

            // center of the item
            double balloonX = balloon->GetX();
            double balloonY = balloon->GetY();

            // the scalar distance between the centers
            double distance = sqrt((explosionX - balloonX) * (explosionX - balloonX) + (explosionY - balloonY) * (explosionY - balloonY));

            // if the distance is shorter than the radius then they are hitting
            if (distance < explosion->GetRadius() && !balloon->IsActiveWeapon(explosion))
            {
                balloon->Damage(explosion->GetDamage());
                balloon->AddActiveWeapon(explosion);
                if (balloon->GetHealth() <= 0)
                {
                    mScoreChange += 2;
                }
            }
            else
            {
                balloon->RemoveActiveWeapon(explosion);
            }
        }

        for (auto explosion : mLevelPumpkinExplosions)
        {
            // if the balloon is in the explosions area it is getting damage done
            // center of the explosion
            double explosionX = explosion->GetX();
            double explosionY = explosion->GetY();

            // center of the item
            double balloonX = balloon->GetX();
            double balloonY = balloon->GetY();

            // if balloon is within bounds created by explosion
            if ((balloonX > (explosionX - (explosion->GetWidth() / 2))
                    && balloonX < (explosionX + (explosion->GetWidth() / 2))
                || balloonY > (explosionY - (explosion->GetWidth() / 2))
                    && balloonY < (explosionY + (explosion->GetWidth() / 2)))
                && !balloon->IsActiveWeapon(explosion))
            {
                balloon->Damage(explosion->GetDamage());
                balloon->AddActiveWeapon(explosion);
                if (balloon->GetHealth() <= 0)
                {
                    mScoreChange += 4;
                }
            }
            else
            {
                balloon->RemoveActiveWeapon(explosion);
            }
        }
    }
}