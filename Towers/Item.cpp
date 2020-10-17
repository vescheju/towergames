/**
 * \file Item.cpp
 *
 * \author Julius Eillya
 */

#include <string>
#include "pch.h"
#include "Item.h"

using namespace Gdiplus;
using namespace std;

/// the length of a tile space in the game
const int tileLength = 64;

 /** Constructor
 * \param game The game this item is a member of
 */
CItem::CItem(CGame* game) :
    mGame(game)
{
    
}
/**
 * Destructor
 */
CItem::~CItem()
{
}


/**
 * Set the image to the specific item
 * \param filename The file for the item image
 */
void CItem::SetImage(const wstring filename) 
{
    mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));

    if (mItemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}

/**  Test this item to see if it has been clicked on
* \param x X location in the game to test
* \param y Y location in the game to test
* \return true if clicked on */
bool CItem::HitTest(int x, int y)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mItemImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mItemImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
    
}


/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 * \param declNode The decleration for a single object
 * \param itemNode The node that is now labeled
 */
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& declNode,
    const std::shared_ptr<xmlnode::CXmlNode>& itemNode) 
{
    const wstring filename = L"images/" + declNode->GetAttributeValue(L"image", L"");

    SetImage(filename);

    SetLocation(itemNode->GetAttributeDoubleValue(L"x", 0) * mTileLength + mTileLength / 2,
        itemNode->GetAttributeDoubleValue(L"y", 0) * mTileLength + mTileLength / 2);

}

/**
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();
    graphics->DrawImage(mItemImage.get(),
        float(mX - wid / 2), float(mY - hit / 2),
        (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
}
