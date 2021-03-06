/**
 * \file LevelProgressor.h
 *
 * \author Julius Eillya
 *
 * A visitor that collects all the game's balloons in a vector to retrieve
 * game process and determine if a level is complete
 */

#pragma once

#include "Balloon.h"
#include "ItemVisitor.h"
#include <vector>


/**
 * A class that determines if there are any more balloons in the level
 */
class CLevelProgressor : public CItemVisitor
{
public:
	virtual void VisitBalloonRed(CBalloonRed* balloon) override;
	virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;

	bool GetProgress();

private:

	/// the collection of balloons in the level
	std::vector<CBalloonRed*> mNumRedBalloons;
	/// the collection of the boss balloon(s) in the level
	std::vector<CBalloonBoss*> mNumBossBalloons;
};

