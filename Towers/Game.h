/**
 * \file Game.h
 * 
 * \author Zach Arnold
 * 
 * Class represents game that all physical objects belong to
 */

#pragma once

#include <vector>
#include <memory>

#include "XmlNode.h"

class CItem;

class CGame
{
public:

	CGame();
	virtual ~CGame();

	void Add(std::shared_ptr<CItem> item);

	void Load(const std::wstring& filename);


private:


	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// vector of all items game is comprised of
	std::vector<std::shared_ptr<CItem> > mItems;

};

