/**
 * \file BalloonRed.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "BalloonRed.h"

using namespace std;


/**
 * Constructor for a red balloon
 *
 * \param game the game that holds everything.
 * \param road the road that the balloon exists on
 * \param heading the initial direction of the road
 */
CBalloonRed::CBalloonRed(CGame* game, CItemRoad* road, std::wstring heading) :
	CBalloon(game, road, heading)
{
}
