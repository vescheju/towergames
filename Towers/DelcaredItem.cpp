/**
 * \file DelcaredItem.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "DelcaredItem.h"
#include "ItemHouse.h"
#include "ItemOpen.h"
#include "ItemRoad.h"
#include "ItemTree.h"

using namespace std;
using namespace Gdiplus;

/// the size of a tile in the game
const int tileSize = 64;

/**
 * Constructor
 * \param node the Xml node for this define
 * \param game the game instance that this declared item exits in
 */
CDeclaredItem::CDeclaredItem(std::shared_ptr<xmlnode::CXmlNode> node, CGame * game)
{
    mGame = game;
    mName = node->GetName();
    mId = node->GetAttributeValue(L"id", L"");
    wstring filename = L"images/" + node->GetAttributeValue(L"image", L"");
    mType = node->GetAttributeValue(L"type", L"");
    mLit = (L"true" == node->GetAttributeValue(L"lit", L""));



    mItemImage = shared_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));

    if (mItemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}



/**
 * intializes a CItem based off of the declaration
 * 
 * \param x the x position to set the item at
 * \param y the y position to set the item at
 * 
 * \return a pointer to the initialized item
 */
shared_ptr<CItem> CDeclaredItem::Initialize(int x, int y)
{
    if (mName == L"road")
    {
        int trueX = x * tileSize + tileSize / 2;
        int trueY = y * tileSize + tileSize / 2;
        shared_ptr<CItemRoad> item = make_shared<CItemRoad>(mGame);
        item->SetImagePtr(mItemImage);
        item->SetLocation(trueX, trueY);
        item->SetRoadDirection(mType);
        item->SetLit(mLit);
        return item;
    }
    else if (mName == L"open")
    {
        int trueX = x * tileSize + tileSize / 2;
        int trueY = y * tileSize + tileSize / 2;
        shared_ptr<CItemOpen> item = make_shared<CItemOpen>(mGame);
        item->SetImagePtr(mItemImage);
        item->SetLocation(trueX, trueY);
        return item;
    }
    else if (mName == L"house")
    {
        int trueX = x * tileSize + tileSize / 2;
        int trueY = y * tileSize + tileSize / 2;
        shared_ptr<CItemHouse> item = make_shared<CItemHouse>(mGame);
        item->SetImagePtr(mItemImage);
        item->SetLocation(trueX, trueY);
        return item;
    }
    else if(mName == L"trees")
    {
        int trueX = x * tileSize + tileSize / 2;
        int trueY = y * tileSize + tileSize / 2;
        shared_ptr<CItemTree> item = make_shared<CItemTree>(mGame);
        item->SetImagePtr(mItemImage);
        item->SetLocation(trueX, trueY);
        return item;
    }

    return nullptr;
}