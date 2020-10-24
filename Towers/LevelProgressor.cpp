/**
 * \file LevelProgressor.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "LevelProgressor.h"
#include "Balloon.h"


/**
 * Visitor to collect red balloons
 * \param balloon The red balloon we are visiting
 */
void CLevelProgressor::VisitBalloonRed(CBalloonRed* balloon)
{
	if (balloon)
	{
		mNumRedBalloons.push_back(balloon);
	}
}


/**
 * Visitor to collect boss balloons
 * \param balloon The boss balloon we are visiting
 */
void CLevelProgressor::VisitBalloonBoss(CBalloonBoss* balloon)
{
	if (balloon)
	{
		mNumBossBalloons.push_back(balloon);
	}
}


/**
 * Uses balloon vectors to determine if there are any remaining in the level
 * \returns True if there are no more balloons in the level
 */
bool CLevelProgressor::GetProgress()
{
	if (mNumBossBalloons.size() == 0 && mNumRedBalloons.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}