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

	CGameMenu(CGame* game);

	~CGameMenu();

	void SetLocation(double x, double y);

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
};