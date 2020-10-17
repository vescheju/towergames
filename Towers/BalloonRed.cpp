/**
 * \file BalloonRed.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "BalloonRed.h"

using namespace std;

/// the filename of the ballon image
const wstring RedBalloonImage = L"images/red-balloon.png";

/**
 * Constructor for a red balloon
 *
 * \param game the game that holds everything.
 */
CBalloonRed::CBalloonRed(CGame* game) : 
	CBalloon(game)
{
	SetImage(RedBalloonImage);
}
