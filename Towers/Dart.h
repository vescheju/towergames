/**
 * \file Dart.h
 *
 * \author Julius Eillya
 *
 * A class that implements a dart to pop balloons 
 */

#pragma once

#include "Item.h"

/**
* A dart item
*/
class CDart : public CItem
{
public:

    ///  Default constructor (disabled)
    CDart() = delete;

    ///  Copy constructor (disabled)
    CDart(const CDart&) = delete;

    CDart(CGame* game, int angle);

    ~CDart();

    void Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitDart(this); }

    void Fire();

    void Draw(Gdiplus::Graphics* graphics) override;

private:

    int mAngle;

};

