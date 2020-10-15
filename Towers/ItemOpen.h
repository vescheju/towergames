/**
 * \file ItemOpen.h
 *
 * \author Julius Eillya
 *
 * A class to represent an open spot in our game
 */

#pragma once
#include "Item.h"


/**
 * An open spot for any item
 */
class CItemOpen : public CItem
{

public:
    CItemOpen(CGame* game);

    ///  Default constructor (disabled)
    CItemOpen() = delete;

    ///  Copy constructor (disabled)
    CItemOpen(const CItemOpen&) = delete;

    ~CItemOpen();
};

