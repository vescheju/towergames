/**
 * \file DelcaredItem.h
 *
 * \author Ian Masterson
 *
 * Class represents a declared Item in the xml file
 */

#pragma once
#include <memory>
#include "XmlNode.h"
#include "Item.h"

class CGame;

/**
 * Class for an item in the "declarations" XML section.
 */
class CDeclaredItem
{
public:
    CDeclaredItem(std::shared_ptr<xmlnode::CXmlNode> node, CGame * game);

    /**
    * returns the ID of the item
    * 
    * \return mId the Id of the item
    */
    std::wstring GetId() { return mId; }

    std::shared_ptr<CItem> Initialize(int x, int y);

private:
    /// the instance of the game that the item exists in
    CGame* mGame;

    /// name of item for this definition
    std::wstring mName;

    /// The ID for this definition
    std::wstring mId;

    /// the pointer to the image bitmap for this delcaration
    std::shared_ptr<Gdiplus::Bitmap> mItemImage;

    /// if it is a road, then the road type if not then L""
    std::wstring mType;

    bool mLit = false; ///< if it is a road then the lit boolean if not then false
};

