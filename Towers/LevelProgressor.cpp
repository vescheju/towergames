#include "pch.h"
#include "LevelProgressor.h"
#include "Balloon.h"

void CLevelProgressor::VisitBalloonRed(CBalloonRed* balloon)
{
	if (balloon)
	{
		mNumRedBalloons.push_back(balloon);
	}
}

void CLevelProgressor::VisitBalloonBoss(CBalloonBoss* balloon)
{
	if (balloon)
	{
		mNumBossBalloons.push_back(balloon);
	}
}

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