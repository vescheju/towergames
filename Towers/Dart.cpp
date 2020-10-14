/**
 * \file Dart.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "Dart.h"


/**
 * Constructor
 * \param game The game this item is a member of
 */
CDart::CDart(CGame* game) : CItem(game) // Not entirely sure if this setup
									// is correct. I am sure the game param
									// is correct but there should be a second
									// but I am unsure of what it should be.
									// Filename is probably what it's expecting so I feel
									// like this is the wrong approach.
{
}


/**
 * Destructor
 */
CDart::~CDart()
{
}