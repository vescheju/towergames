/**
 * \file Game.h
 * 
 * \author Zach Arnold
 * 
 * Class represents game that all physical objects belong to
 */

#pragma once

#include <vector>
#include <memory>
#include "XmlNode.h"
#include "ItemVisitor.h"
#include "ImageContainer.h"

class CItem;
class CTower;

/// implements a game
class CGame
{

private:
    /// the name of the current level
    std::wstring mLevel = L"Level 0";

    /// pointer to the menu in the game
    std::shared_ptr<CGameMenu> mMenu;

    /// the collection of items in the game
	std::vector<std::shared_ptr<CItem> > mItems;

    /// the starting column of the game
    int mStartX;
    /// the starting row of the game
    int mStartY;
    /// the number of columns in the game
    int mLevelWidth;
    /// the number of rows in the game
    int mLevelHeight;

    /// Game area in virtual pixels
    const static int mWidth = 1224;

    /// Game area height in virtual pixels
    const static int mHeight = 1024;

    /// the scaling factor of the game
    float mScale = 1;

    /// the x offset of the game
    float mXOffset = 0;

    /// the y offset of the game
    float mYOffset = 0;

    /// the length of a item tile in the game
    const int mTileLength = 64;

    /// the number of balloons per level
    int mLevelBalloons = 30;

    /// the spacing of the balloons in the game
    int mBalloonSpacing = 42;

    /// tells if the game should operate
    bool mButtonPressed = false;

    /// Any tower we are currently dragging
    std::shared_ptr<CTower> mGrabbedItem;

	/// calculate score to display
	int mScore = 0;

    /// container of the images in the level
    CImageContainer mImages;

    /// The current level of the game.
    int mGameLevel = 0;

    /// Check if the end should be displayed
    bool mDisplayEnd = false;

    /// the check to see if the jump scare needs to be displayed
    bool mScare = false;

    /// keeps track of how long to display the jumpscare image
    double mScareTime = 0;

    /// whether or not pumpkin exists currently in game
    bool mPumpkin = false;

public:

    /**
    * getter for the score of the level
    * 
    * \return the current score
    */
	int GetScore() { return mScore; };

    /**
    * getter for whether or not pumpkin in game
    *
    * \return bool value of mPumpkin
    */
    bool GetPumpkin() const { return mPumpkin; };

    /**
    * setter for whether or not pumpkin in game
    *
    * \param pumpkin bool value for mPumpkin
    */
    void SetPumpkin(bool pumpkin) { mPumpkin = pumpkin; };

    /**
    * getter for the display end
    *
    * \return mDisplayEnd
    */
    int GetDisplayEnd() { return mDisplayEnd; };

    /**
    * getter for the level
    *
    * \return mGameLevel the current level
    */
    int GetGameLevel() { return mGameLevel; };

    /**
    * Setter for the level
    *
    * \param level an int of what level to set.
    */
    void SetGameLevel(int level) { mGameLevel = level; };

	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void Add(std::shared_ptr<CItem> item);
	
	void Clear();

	void Load(const std::wstring& filename);

    void Update(double elapsed);

    void ProgressLevel();

    void Accept(CItemVisitor* visitor);

    void InitializeStart(bool pumpkin);

    std::shared_ptr<Gdiplus::Bitmap> GetImage(std::wstring filename);

    /// boolean if Go button has been pushed
    /// \return True if pressed
	bool GetButtonPressed() { return mButtonPressed; };

	std::shared_ptr<CTower> HitTest(int x, int y);

    void OnLButtonDown(UINT nFlags, CPoint point);

    void CGame::OnMouseMove(UINT nFlags, CPoint point);

    void CGame::OnLButtonUp(UINT nFlags, CPoint point);

    void Remove(std::vector<CItem*> items);

    void TowersToFrontOfScreen(std::vector<CTower*> towers);

    void ToFrontOfScreen(std::shared_ptr<CItem> item);
    
    /// returns the xOffset
    /// \return level xOffset
    float GetXOffset() { return mXOffset; }

    /// returns the yOffset
    /// \return level yOffset
    float GetYOffset() { return mYOffset; }

    /// returns the scale of the game
    /// \return the scale
    float GetScale() { return mScale; }

    /// returns the width of the level in pixels
    /// \return level width in pixels
    int GetGameWidth() { return mTileLength * mLevelWidth; }

    /// returns the height of the level in pixels
    /// \return level height in pixels
    int GetGameHeight() { return mTileLength * mLevelHeight; }

    /// setter for the start x
    /// \param x the start x
    void SetStartX(int x) { mStartX = x; }

    /// setter for the start y
    /// \param y the start y
    void SetStartY(int y) { mStartY = y; }

    /// setter for the level width
    /// \param width the number of tiles
    void SetLevelWidth(int width) { mLevelWidth = width; }

    /// setter for the level width
    /// \param height the number of tiles
    void SetLevelHeight(int height) { mLevelHeight = height; }

    /// setter for the button pressed
    /// \param set the value to assigne to mButtionPressed
    void SetButtonPressed(bool set) { mButtonPressed = set; }

    /// getter for the start x
    /// \return the start x
    int GetStartX() { return mStartX; }

    /// getter for the start y
    /// \return the start y
    int GetStartY() { return mStartY; }

    /// getter for the level width
    /// \return the number of tiles
    int GetLevelWidth() { return mLevelWidth; }

    /// getter for the level height
    /// \return the number of tiles
    int GetLevelHeight() { return mLevelHeight; }

    /// returns the number of items in the game
    /// \return size of mItems
    int GetItemNumber() { return mItems.size(); }

    /**
    * Setter for mScare
    * 
    * \param scare the value to set to mScare
    */
    void SetScare(bool scare) { mScare = scare; }
    

    
    /** Iterator that iterates over the game items */
    class Iter
    {
    public:
        /** Constructor
         * \param game The game we are iterating over
         * \param pos The poition to be placed
         */
        Iter(CGame* game, int pos) : mGame(game), mPos(pos) {}

        /** Test for end of the iterator
         * \param other other iterator to be compared to
         * \returns True if we this position not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        std::shared_ptr<CItem> operator *() const { return mGame->mItems[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */


        const Iter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CGame* mGame;   ///< City we are iterating over
        int mPos;       ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mItems.size()); }


};

