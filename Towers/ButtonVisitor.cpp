/**
 * \file ButtonVisitor.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include "ButtonVisitor.h"

/**
 * This function will set true if a button is clicked.
 *
 * \param button potential button being searched for.
 */
void CButtonVisitor::VisitGoButton(CGoButton* button)
{
	mGoClicked = true;
}
