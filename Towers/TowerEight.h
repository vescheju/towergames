/**
 * \file TowerEight.h
 *
 * \author Hithesh Yedlapati
 *
 * Tower 8 class derived from CTower
 */

#pragma once
#include "Tower.h"

/**
* releases 8 darts
*/
class CTowerEight :
	public CTower
{
public:
	/// constructor
	CTowerEight(CGame* game);

	/// Default constructor (disabled)
	CTowerEight() = delete;

	/// Copy constructor (disabled)
	CTowerEight(const CTowerEight&) = delete;

private:

};

