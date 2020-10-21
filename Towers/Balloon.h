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
#include "ItemRoad.h"

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
	 * Getter for mSpeed
	 *
	 * \return mSpeed or speed of the balloon.
	 */
	double GetSpeed() const { return mSpeed; }

	/**
	 * Getter for mHealth
	 *
	 * \return mHealth or health of the balloon.
	 */
	int GetHealth() const { return mHealth; }

	void UpdateLocation(double elapsed);

	void UpdateHeading();

	virtual void Update(double elapsed) override;

	/**
	* returns the road member
	* 
	* \return the road that the balloon is on
	*/
	CItemRoad* GetRoad() { return mRoad; }

	/**
	* returns the heading
	*
	* \return the direction that the balloon is moving
	*/
	std::wstring GetHeading() { return mHeading; }

	/**
	* subtracts damage from the balloons health
	* 
	* \param damage the decrease in health
	*/
	void Damage(int damage) { mHealth -= damage; }

	/**
	* getter fot mHealth
	* 
	* \return the health of the balloon
	*/
	int GetHealth() { return mHealth; }
protected:

	CBalloon(CGame* game, CItemRoad* road, std::wstring heading);

private:
	/// the direction that the balloon is moving in
	std::wstring mHeading;
	/// pointer to the road that the balloon is currently on
	CItemRoad* mRoad = nullptr;
	/// health of a balloon (default is 1 hp).
	int mHealth = 1;
	/// speed of the balloon in pixels per second (default at 128 p/s).
	double mSpeed = 128;

};

