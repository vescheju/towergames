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
	CDart(CGame* game);

    ///  Default constructor (disabled)
    CDart() = delete;

    ///  Copy constructor (disabled)
    CDart(const CDart&) = delete;

    ~CDart();

    void Draw(Gdiplus::Graphics* graphics, int offsetX, int offsetY);

};

