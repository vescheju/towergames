#include "pch.h"
#include "Game.h"
#include "ItemRoad.h"
#include "ItemHouse.h"
#include "ItemTree.h"
#include "ItemOpen.h"

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
  * Draw the aquarium
  * \param graphics The GDI+ graphics context to draw on
  */
void CGame::OnDraw(Gdiplus::Graphics* graphics)
{
    for (auto item : mItems)
    {
        item->Draw(graphics);
    }
}

void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& declNode, 
    const std::shared_ptr<xmlnode::CXmlNode>& itemNode)
{
    // pointer for the item we are loading
    shared_ptr<CItem> item;

    // get the type of the item
    wstring name = declNode->GetName();

    if (name == L"road")
    {
        item = make_shared<CItemRoad>(this);
    }
    else if (name == L"open")
    {
        item = make_shared<CItemOpen>(this);
    }
    else if (name == L"house") 
    {
        item = make_shared<CItemHouse>(this);
    }
    else if (name == L"trees")
    {
        item = make_shared<CItemTree>(this);
    }

    if (item != nullptr)
    {
        item->XmlLoad(declNode, itemNode);
        Add(item);
    }
}

void CGame::Load(const std::wstring& filename) 
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(levelFolder + filename);

        // Once we know it is open, clear the existing data
        Clear();

        //
        // Traverse the items of the root node
        // and match them with a declaration and pass both
        // nodes to XmlItem

        //get the declaration and item nodes
        shared_ptr<CXmlNode> declarations = root->GetChild(0);
        shared_ptr<CXmlNode> items = root->GetChild(1);
        
        for (auto itemNode : items->GetChildren())
        {
            for (auto declNode : declarations->GetChildren())
            {
                if (itemNode->GetAttributeValue(L"id", L"") == declNode->GetAttributeValue(L"id", L""))
                {
                    XmlItem(declNode, itemNode);
                }
            }
        }

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
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