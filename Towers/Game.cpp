#include "pch.h"
#include "Game.h"

CGame::CGame()
{
}

CGame::~CGame()
{
}


/** Add an item to the game
 * 
 * \param item Item to add to game's mItems vector
 */
void CGame::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}


/** Load game from level XML file
 *  
 * \param filename Name of file to load game from
 */
void CGame::Load(const std::wstring& filename)
{
}

/**
*  Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CGame::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
