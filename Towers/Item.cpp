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


/**
 * Getter function for Item's image
 * \return Pointer to Bitmap of Item's image
 */
std::shared_ptr<Gdiplus::Bitmap> CItem::GetImage()
{
    return mItemImage;
}

/**  Test this item to see if it has been clicked on
* \param x X location in the game to test
* \param y Y location in the game to test
* \return true if clicked on */
bool CItem::HitTest(int x, int y)
{
    if (mItemImage == nullptr)
    {
        return false;
    }
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
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics)
{
    if (mItemImage != nullptr)
    {
        double wid = mItemImage->GetWidth();
        double hit = mItemImage->GetHeight();
        graphics->DrawImage(mItemImage.get(),
            float(mX - wid / 2), float(mY - hit / 2),
            (float)mItemImage->GetWidth()+1, (float)mItemImage->GetHeight()+1);
    }
}


/**
 * checks if the images are overlapping at all
 * 
 * \param item the item to compare its image too
 * \returns true if the drawn images are overlapping
 */
bool CItem::ImagesAreOverlapping(CItem* item)
{
    double thisX = this->GetX();
    double thisY = this->GetY();

    double thisImageWidth = this->GetImage()->GetWidth();
    double thisImageHeight = this->GetImage()->GetHeight();
    
    double itemX = item->GetX();
    double itemY = item->GetY();

    double itemImageWidth = item->GetImage()->GetWidth();
    double itemImageHeight = item->GetImage()->GetHeight();

    // see if the  images overlap
    if (abs(itemX - thisX) <= itemImageWidth / 2 + thisImageWidth / 2 &&
        abs(itemY - thisY) <= itemImageHeight / 2 + thisImageHeight / 2)
    {
        // get the bounds of the overlap
        double overlapXLower = -1; // the lower bound of the overlap in the x direction
        double overlapXUpper = -1; // the upper bound of the overlap in the x dicrection
        double overlapYLower = -1; // the lower bound of the overlap in the y direction
        double overlapYUpper = -1; // the upper bound of the overlap in the y dicrection
        // the overlap in the x direction
        if (itemX < thisX)
        {
            overlapXLower = thisX - thisImageWidth / 2;
            overlapXUpper = itemX + itemImageWidth / 2;
        }
        else if (itemX > thisX)
        {
            overlapXLower = itemX - itemImageWidth / 2;
            overlapXUpper = thisX + thisImageWidth / 2;
        }
        else
        {
            overlapXLower = itemX - itemImageWidth / 2;
            overlapXUpper = itemX + itemImageHeight / 2;
        }
        // overlap int he y direction
        if (itemY < thisY)
        {
            overlapYLower = thisY - thisImageHeight / 2;
            overlapYUpper = itemY + itemImageHeight / 2;
        }
        else if (itemY > thisY)
        {
            overlapYLower = itemY - itemImageHeight / 2;
            overlapYUpper = thisY + thisImageHeight / 2;
        }
        else
        {
            overlapYLower = itemY - itemImageHeight / 2;
            overlapYUpper = itemY + itemImageHeight / 2;
        }
        // check all points in the overlap to see if any 2 visible pixels
        // are overlapping
        auto format1 = item->GetImage()->GetPixelFormat();
        auto format2 = this->GetImage()->GetPixelFormat();
        if ((format1 == PixelFormat32bppARGB || format1 == PixelFormat32bppPARGB) &&
            (format2 == PixelFormat32bppARGB || format2 == PixelFormat32bppPARGB))
        {
            Color color1;
            Color color2;
            for (int x = overlapXLower; x <= overlapXUpper; ++x)
            {
                for (int y = overlapYLower; y <= overlapYUpper; ++y)
                {
                    item->GetImage()->GetPixel((int)x, (int)y, &color1);
                    this->GetImage()->GetPixel((int)x, (int)y, &color1);
                    return color1.GetAlpha() != 0 && color2.GetAlpha() != 0;

                }
            }
        }
        else
        {
            return true;
        }

    }
    return false;
}
