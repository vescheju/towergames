/**
 * \file ItemTree.h
 *
 * \author Julius Eillya
 *
 * A class that implements a tree item
 */

#pragma once

#include "Item.h"


/**
 * A tree item
 */
class CItemTree : public CItem
{
public:
    CItemTree(CGame* game);

    ///  Default constructor (disabled)
    CItemTree() = delete;

    ///  Copy constructor (disabled)
    CItemTree(const CItemTree&) = delete;

    ~CItemTree();

};
