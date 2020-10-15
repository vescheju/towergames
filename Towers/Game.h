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

	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	std::vector<std::shared_ptr<CItem> > mItems;

};

