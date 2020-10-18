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

private:
	/// pointer to Go button
	CGoButton* mGoButton = nullptr;

	/// pointer to Tower Eight
	CTowerEight* mEight = nullptr;

	/// pointer to Tower Bomb
	CBombTower* mBomb = nullptr;

	/// pointer to Tower Ring
	CRingTower* mRing = nullptr;
};