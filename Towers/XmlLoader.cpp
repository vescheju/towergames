/**
 * \file XmlLoader.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "XmlLoader.h"

using namespace std;
using namespace xmlnode;


/**
 * Constructor
 * 
 * \param game the game that the xml loader exists in
 */
CXmlLoader::CXmlLoader(CGame* game) : mGame(game)
{
    
}


 /**
  * Load the file from XML
  * \param filename The file to load.
  * \return true if successful
  */
bool CXmlLoader::Load(const std::wstring& filename)
{
    try
    {
        wstring path = L"levels/" + filename;
        shared_ptr<CXmlNode> root =
            xmlnode::CXmlNode::OpenDocument(path);

        // set the level information in the root node
        mGame->SetStartX(root->GetAttributeIntValue(L"start-x", 0));
        mGame->SetStartY(root->GetAttributeIntValue(L"start-y", 0));
        mGame->SetLevelWidth(root->GetAttributeIntValue(L"width", 0));
        mGame->SetLevelHeight(root->GetAttributeIntValue(L"height", 0));

        for (auto child : root->GetChildren())
        {
            if (child->GetType() == NODE_ELEMENT)
            {
                std::wstring name = child->GetName();

                // Handle the different tags here "declarations" and "items"
                if (name == L"declarations")
                {
                    XmlDeclare(child);
                }
                else if (name == L"items")
                {
                    XmlInitialize(child);
                }

            }
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

    return true;
}

/**
 * Handle the Xml node declarations
 * \param node The XML node
 */
void CXmlLoader::XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node)
{
    for (auto child : node->GetChildren())
    {
        if (child->GetType() == NODE_ELEMENT)
        {
            XmlDeclareItem(child);
        
        }
    }
}

/**
 * Handle the Xml node item that is within a declarations tag.
 * \param node The XML node
 */
void CXmlLoader::XmlDeclareItem(std::shared_ptr<xmlnode::CXmlNode> node)
{
    auto declaredItem = make_shared<CDeclaredItem>(node, mGame);

    // Add to the collection
    mDeclarations[declaredItem->GetId()] = declaredItem;
}

/**
 * Handle the Xml node "items"
 * \param node The XML node
 */
void CXmlLoader::XmlInitialize(std::shared_ptr<xmlnode::CXmlNode> node)
{
    for (auto child : node->GetChildren())
    {
        if (child->GetType() == NODE_ELEMENT)
        {
            XmlInitializeItem(child);

        }
    }
}

/**
 * Handle an any tag inside "items"
 * \param node The XML node
 */
void CXmlLoader::XmlInitializeItem(std::shared_ptr<xmlnode::CXmlNode> node)
{
    // Get the id
    auto id = node->GetAttributeValue(L"id", L"");

    int xPos = node->GetAttributeIntValue(L"x", 0);
    int yPos = node->GetAttributeIntValue(L"y", 0);

    // Find the definition associated with this id
    auto iterator = mDeclarations.find(id);
    if (iterator != mDeclarations.end())
    {
        // We found it
        auto declaration = iterator->second;

        mInitializedItems.push_back(declaration->Initialize(xPos, yPos));
    }
}