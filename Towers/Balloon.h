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
  * This applies to all of the balloon
  * items in the game.
  */
class CBalloon : public CItem
{
public:
	/// Default construct disabled
	CBalloon() = delete;

	/// Copy construct disabled
	CBalloon(const CBalloon&) = delete;

	// void Update(double elapsed);

	/**
	 * Set the speed of the balloon.
	 * \param speed the speed to be set.
	 */
	void SetSpeed(double speed) { mSpeed = speed; }

	

	/**
	 * Getter for mT
	 * 
	 * \return mT or the scalar position of the balloon on a tile.
	 */
	double GetT() const { return mT; }

	/**
	 * Getter for mSpeed
	 *
	 * \return mSpeed or speed of the balloon.
	 */
	double GetSpeed() const { return mSpeed; }

protected:

	CBalloon(CGame* game);
private:
	/// The scalar unit for the position of the balloon on a tile
	double mT = 0;
	/// health of a balloon (default is 1 hp).
	int mHealth = 1;
	/// speed of the balloon in pixels per second (default at 128 p/s).
	double mSpeed = 128;

};

