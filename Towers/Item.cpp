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

 /** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CGame* game, const std::wstring& filename) :
    mGame(game)
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
 * Destructor
 */
CItem::~CItem()
{
}
