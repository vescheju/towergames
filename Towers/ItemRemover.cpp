/**
 * \file ItemRemover.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "ItemRemover.h"
#include "BalloonRed.h"


/**
 * adds red balloons to a vector of they need to be removed
 * \param balloon the button being visited
 */
void CItemRemover::VisitBalloonRed(CBalloonRed* balloon)
{
	if (balloon->GetHealth() <= 0)
	{
		mRemovedItems.push_back(balloon);
	}
}
