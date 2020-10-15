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
/**
* Base Class for each of the different towers, derived from CItem
*/
class CTower : public CItem
{
public:
	/// constructor disabled
	CTower() = delete;

	/// copy constructor
	CTower(const CTower&) = delete;

	/// constructor
	CTower(CGame* game);

private:
};

