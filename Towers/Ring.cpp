/**
 * \file Ring.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "Ring.h"

using namespace Gdiplus;

//std::shared_ptr<Pen> RedPen(Color.Red, 1);

/**
* Ring Constructor function
*\param game representing the game as a whole
*/
CRing::CRing(CGame* game) : CItem(game)
{

}

/**
 * Destructor
 */
CRing::~CRing()
{

}


/**
 * Draw our ring
 * \param graphics The graphics context to draw on
 */
void CRing::Draw(Gdiplus::Graphics* graphics)
{
	Pen pen(Color(0, 128, 0), 3);
	//graphics.DrawEllipse(pen, 200, 200, 20, 20);
}

