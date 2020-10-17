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
#include "XmlNode.h"

class CGame;

/**
 * Base class for any item in our game
 */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	CItem(CGame* game);

	~CItem();

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	virtual bool HitTest(int x, int y);


	void SetImage(const std::wstring filename);

	/**
	* sets the image directly using a pointer
	* 
	* \param itemImage pointer to the image bitmap
	*/
	void SetImagePtr(std::shared_ptr<Gdiplus::Bitmap> itemImage) { mItemImage = itemImage; }

	void Draw(Gdiplus::Graphics* graphics);

	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

private:
	/// The towers game the item is contained in
	CGame* mGame;

	/// Item location in the game
	double mX = 0;		///< X location for the center of the item
	double mY = 0;		///< Y location for the center of the item

	/// The file for this item
	std::wstring mFile;

	/// The image of an item
	std::shared_ptr<Gdiplus::Bitmap> mItemImage;

protected:
	const int mTileLength = 64;		///< The length of a tile space
};

