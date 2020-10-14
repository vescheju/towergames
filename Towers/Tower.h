/**
 * \file Tower.h
 *
 * \author Hithesh Yedlapati
 *
 * Base Class for all towers
 */

#pragma once
#include "Item.h"
#include "XmlNode.h"
#include <memory>

class CGame;

class CTower : public CItem
{
public:
	/// constructor disabled
	CTower() = delete;

	CTower(const CTower&) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	CTower(CGame* game, const std::wstring& filename);

private:
	double mLocX;
	double mLocY;
};

