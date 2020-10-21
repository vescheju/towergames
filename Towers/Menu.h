/**
 * \file Menu.h
 *
 * \author Julius Eillya
 *
 * A class that implements the menu for the game
 */

#pragma once

#include "Item.h"

class CGame;
class CScore;

/**
 * Implements a menu into the game
 */
class CGameMenu : public CItem
{
public:
	/// Default constructor disabled
	CGameMenu() = delete;

	/// Copy constructor disabled
	CGameMenu(const CGameMenu&) = delete;

	/// constructor
	CGameMenu(CGame* game);

	/// destructor
	~CGameMenu();

	/** set location of menu
	* \param x location of item along x axis
	* \param y location of item along y axis
	*/
	void SetLocation(double x, double y);

	/** draw for menu border, scoreboard, and level display text
	* \param graphics
	*/
	void Draw(Gdiplus::Graphics* graphics);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMenu(this); }

private:
	/// pointer to Go button
	std::shared_ptr<CGoButton> mGoButton = nullptr;

	/// pointer to Tower Eight
	std::shared_ptr<CTowerEight> mEight = nullptr;

	/// pointer to Tower Bomb
	std::shared_ptr<CBombTower> mBomb = nullptr;

	/// pointer to Tower Ring
	std::shared_ptr<CRingTower> mRing = nullptr;

	/// pointer to Scoreboard
	std::shared_ptr<CScoreboard> mScore = nullptr;
};