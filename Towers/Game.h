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

class CItem;

/// implements a game
class CGame
{

private:
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
    const static int Width = 1224;

    /// Game area height in virtual pixels
    const static int Height = 1024;

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

public:
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void Add(std::shared_ptr<CItem> item);
	
	void Clear();

	void Load(const std::wstring& filename);

    void Update(double elapsed);

    void Accept(CItemVisitor* visitor);

    void InitializeStart();

	std::shared_ptr<CItem> HitTest(int x, int y);
    
    /// returns the width of the level in pixels
    /// \return level width in pixels
    double GetGameWidth() { return mTileLength * mLevelWidth; }

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

