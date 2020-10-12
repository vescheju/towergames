#pragma once
#include "Item.h"
#include "XmlNode.h"
#include <memory>
class CTower : public CItem
{
public:
	CTower() = delete;

	CTower(const CTower&) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);
};

