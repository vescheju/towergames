/**
 * \file Item.h
 *
 * \author Julius Eillya
 *
 * Class that describes any item we can add to our Towers game
 */

#pragma once

#include <memory>
#include <string>

class CGame;

class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	~CItem();

protected:
	/// Pass through a pointer to the game and the filename
	/// \param filename The name of the file
	CItem(CGame* game, const std::wstring& filename);

private:
	/// The towers game the item is contained in
	CGame* mGame;

	/// Item location in the game
	double mX = 0;		///< X location for the center of the item
	double mY = 0;		///< Y location for the center of the item

	/// The file for this item
	std::wstring mFile;

	/// The image of an item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
};

