#pragma once
#include "Item.h"
class CItemOpen :
    public CItem
{

public:
    CItemOpen(CGame* game);

    ///  Default constructor (disabled)
    CItemOpen() = delete;

    ///  Copy constructor (disabled)
    CItemOpen(const CItemOpen&) = delete;

    ~CItemOpen();
};

