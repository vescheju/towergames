/**
 * \file Dart.h
 *
 * \author Julius Eillya
 *
 * A class that implements a dart to pop balloons 
 */

#pragma once


#include "Weapon.h"

/**
* A dart item
*/
class CDart : public CWeapon
{
public:

    ///  Default constructor (disabled)
    CDart() = delete;

    ///  Copy constructor (disabled)
    CDart(const CDart&) = delete;

    CDart(CGame* game, int angle);

    ~CDart();

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDart(this); }

    /** Getter function for Dart's Angle
     * \return int value of angle dart is rotated at
     */
    double GetAngle() const { return mAngle; }

    void Draw(Gdiplus::Graphics* graphics) override;

private:

    int mAngle;         ///< Int representing angle at which to draw Dart.

};

