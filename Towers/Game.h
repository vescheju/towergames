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

private:

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node, 
		const std::shared_ptr<xmlnode::CXmlNode>& itemNode);

	std::vector<std::shared_ptr<CItem> > mItems;

public:
	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);
	
	void Clear();

	void Load(const std::wstring& filename);
};

