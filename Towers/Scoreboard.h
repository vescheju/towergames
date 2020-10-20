#pragma once
#include "Item.h"
class CScoreboard :
	public CItem
{
public:
	/// Default constructor disabled
	CScoreboard() = delete;

	/// Copy constructor disabled
	CScoreboard(const CScoreboard&) = delete;

	CScoreboard(CGame* game);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitScoreBoard(this); }

private:
	CScoreboard* mScoreboard;
};

