/**
 * \file XmlLoader.h
 *
 * \author Ian Masterson
 *
 * Class that loads information about the level and items 
 * from an Xml file
 */

#pragma once

#include <string>
#include <memory>
#include <map>
#include <vector>
#include "XmlNode.h"
#include "Item.h"
#include "DelcaredItem.h"
#include "Game.h"

class CDeclaredItem;

/**
 * class that loads XML file and implements the items
 */
class CXmlLoader
{
public:
    /// remove default constructor
    CXmlLoader() = delete;

    CXmlLoader(CGame* game);

    bool Load(const std::wstring& filename);

    /// return a reference to the intitialized items
    /// \return the reference to the items
    std::vector<std::shared_ptr<CItem> >& GetItems() { return mInitializedItems; }

    /// getter used for unit testing 
    /// \return the number of declarations
    int GetDeclarationSize() { return mDeclarations.size(); }

private:

    void XmlDeclare(std::shared_ptr<xmlnode::CXmlNode> node);
    void XmlDeclareItem(std::shared_ptr<xmlnode::CXmlNode> node);
    void XmlInitialize(std::shared_ptr<xmlnode::CXmlNode> node);
    void XmlInitializeItem(std::shared_ptr<xmlnode::CXmlNode> node);

    /// the gaem instance that this xml loader is in
    CGame* mGame;

    /// All of the declarations for this file
    std::map<std::wstring, std::shared_ptr<CDeclaredItem>> mDeclarations;

    /// All initialized Items in the file
    std::vector<std::shared_ptr<CItem> > mInitializedItems;
};



