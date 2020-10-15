/**
 * \file ItemRoad.h
 *
 * \author Julius Eillya
 *
 * A class that implements a road item
 */


#pragma once

#include "Item.h"


/**
 * A road item
 */
class CItemRoad : public CItem
{
public:
    CItemRoad(CGame* game);

    ///  Default constructor (disabled)
    CItemRoad() = delete;

    ///  Copy constructor (disabled)
    CItemRoad(const CItemRoad&) = delete;

    ~CItemRoad();

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& declNode,
        const std::shared_ptr<xmlnode::CXmlNode>& itemNode);

private:
    std::wstring mRoadDirection;

};

