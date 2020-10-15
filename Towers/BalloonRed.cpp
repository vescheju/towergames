/**
 * \file BalloonRed.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include <string>
#include "BalloonRed.h"

using namespace std;

const wstring redBalloonImage = L"red-balloon.png";

CBalloonRed::CBalloonRed(CGame* game) : 
	CBalloon(game)
{
	SetImage(redBalloonImage);
}
