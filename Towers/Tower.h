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


	CTower(CGame* game);

private:
	double mLocX = 0;
	double mLocY = 0;
};

