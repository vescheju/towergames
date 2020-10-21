/**
 * \file Scoreboard.h
 *
 * \author Hithesh Yedlapati
 *
 * Scoreboard Class to update when balloon gets popped
 */

#pragma once
#include "Item.h"

/**
* Class shows the score in the menu
*/
class CScoreboard :
	public CItem
{
public:
	/// Default constructor disabled
	CScoreboard() = delete;

	/// Copy constructor disabled
	CScoreboard(const CScoreboard&) = delete;

	/// score constructor
	CScoreboard(CGame* game);

	/// override accept function
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitScoreBoard(this); }

private:
};

