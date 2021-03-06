/**
 * \file Menu.h
 *
 * \author Julius Eillya
 *
 * A class that implements the menu for the game
 */

#pragma once

#include "Item.h"
#include "Tower.h"

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


	void Draw(Gdiplus::Graphics* graphics) override;

	void Update(double elapsed) override;

	void AddPumpkin();

	std::shared_ptr<CTower> MenuHitTest(double x, double y);


	/**
	* Accepts a visitor into the menu
	* \param visitor the visitor to accept
	*/
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitMenu(this); }

	/**
	* Getter for mEndGame
	* \return mEndGame
	*/
	bool GetEndGame() { return mEndGame; }

private:
	/// pointer to Go button
	std::shared_ptr<CGoButton> mGoButton = nullptr;

	/// pointer to Tower Eight
	std::shared_ptr<CTowerEight> mEight = nullptr;

	/// pointer to Tower Bomb
	std::shared_ptr<CRedBombTower> mBomb = nullptr;

	/// pointer to Tower Pumpkin
	std::shared_ptr<CPumpkinTower> mPumpkin = nullptr;

	/// pointer to Tower Ring
	std::shared_ptr<CRingTower> mRing = nullptr;



	double mTimeSec = 0; ///< Time elapsed in seconds

	double mTimeFreeze = 0; ///< Time elapsed frozen in seconds

	/// boolean to see if game is finished.
	bool mEndGame = false;
	
	/// Level 3 starting text image
	std::unique_ptr<Gdiplus::Bitmap> mLevel3StartText;

	/// Level 3 ending text image
	std::unique_ptr<Gdiplus::Bitmap> mLevel3EndText;
};