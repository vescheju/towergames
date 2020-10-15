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

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& declNode,
		const std::shared_ptr<xmlnode::CXmlNode>& itemNode);

	void SetImage(const std::wstring filename);

	void Draw(Gdiplus::Graphics* graphics);

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

protected:
	const int mTileLength = 64;
};

