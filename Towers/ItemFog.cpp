/**
 * \file ItemFog.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "ItemFog.h"



/**
 * constructor for the Fog
 * \param game the game instance the fog exists in
 */
CItemFog::CItemFog(CGame* game) : CItem(game)
{

}

 /**
  * updates the fogs loacation
  * 
  * \param elapsed time since last update
  */
void CItemFog::Update(double elapsed)
{
	SetLocation(GetX() - (mRetreatSpeed * elapsed), GetY());
}
