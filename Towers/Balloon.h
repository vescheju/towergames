/**
 * \file Balloon.h
 *
 * \author Justin Vesche
 *
 * Class that bases a balloon
 *
 * This class creates a foundation that can describe
 * different balloons.
 */



#pragma once
#include <string>
#include "Item.h"

class CGame;
 /**
  * Base class for a balloon
  * This applies to all of the ballon
  * items in the game.
  */
class CBalloon : public CItem
{
	/// Default construct disabled
	CBalloon() = delete;

	/// Copy construct disabled
	CBalloon(const CBalloon&) = delete;

	void Update(double elapsed);

	/**
	 * Set the speed of the balloon.
	 * \param speed the speed to be set.
	 */
	void setSpeed(double speed) { mSpeed = speed; }

protected:
	CBalloon(CGame* game, const std::wstring& filename);


private:
	/// The scalar unit for the position of the balloon on a tile
	double mT;
	/// health of a balloon.
	int mHealth;
	/// speed of the balloon.
	double mSpeed;

};

