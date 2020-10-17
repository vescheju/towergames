#include "pch.h"
#include "Game.h"
#include "ItemRoad.h"
#include "ItemHouse.h"
#include "ItemTree.h"
#include "ItemOpen.h"
#include "XmlLoader.h"

using namespace std;
using namespace xmlnode;
using namespace Gdiplus;

/// the folder that the levels exist in
const wstring levelFolder = L"levels/";

/**
 * Add an item to the game
 * \param item New item to add
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/**
  * Draw the game
  * \param graphics The GDI+ graphics context to draw on
  */
void CGame::OnDraw(Gdiplus::Graphics* graphics)
{
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }
}

/**
 * Load the level from an XML file.
 *
 * passes the filename to the Xml Loader
 *
 * \param filename The filename of the level to load the level from.
 */
void CGame::Load(const std::wstring& filename)
{

    // Open the document with the xml loader class
    CXmlLoader xmlLoader(this);
    xmlLoader.Load(filename);

    // Once we know it is open, clear the existing items
    Clear();

    // Set the mItems to the new ones from the file
    mItems = xmlLoader.GetItems();

    // ADD BALOONS AND START ROADS TO ITEMS
}

/**
 * Obtain information of the item clicked on.
 *
 * \param x An int of the x location
 * \param y an int of the y location
 * \return share_ptr of the object located at the location
 */
std::shared_ptr<CItem> CGame::HitTest(int x, int y)
{
    for (auto item : *this)
    {
        if (item->HitTest(x, y))
        {
            return item;
        }
    }

    return  nullptr;
}

/**
 * Clear the aquarium data.
 *
 * Deletes all known items in the aquarium.
 */
void CGame::Clear()
{
    mItems.clear();
}

/** Handle updates for animation
* \param elapsed The time since the last update
*/
void CGame::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}