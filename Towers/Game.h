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

class CItem;

class CGame
{

private:

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, 
		const std::shared_ptr<xmlnode::CXmlNode>& itemNode);

	std::vector<std::shared_ptr<CItem> > mItems;

public:
	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);
	
	void Clear();

	void Load(const std::wstring& filename);

	std::shared_ptr<CItem> HitTest(int x, int y);



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

