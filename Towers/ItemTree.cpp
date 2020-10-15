/**
 * \file ItemTree.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "ItemTree.h"

using namespace std;

/// Item filename 
//const wstring ItemTreeOneImageName = L"images/trees1.png";

/**
 * Constructor
 * \param game The game this item belongs to
 */
CItemTree::CItemTree(CGame* game) : CItem(game)
{
}

 /**
  * Destructor
  */
CItemTree::~CItemTree()
{
}

