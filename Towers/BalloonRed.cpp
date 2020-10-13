/**
 * \file BalloonRed.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "BalloonRed.h"

using namespace std;

const wstring RedBalloonImage = L"red-balloon.png";
/**
 *
 * comment
 */
CBalloonRed::CBalloonRed(CGame* game) : 
	CBalloon(game, RedBalloonImage)
{
	// add speed 
}
