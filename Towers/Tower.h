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
class CItemOpen;


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

	CTower(CGame* game);

	void UpdateTimeTillFire(double elapsed);

	/** Getter function for mFire member
	 * \return Boolean of mFire
	 */
	bool GetFire() const { return mFire; }

	/** Setter function for mFire member
	 * \param fire Boolean to set mFire to
	 */
	void SetFire(bool fire) { mFire = fire; }

	/** Setter function for mTimeTillFire member
	 * \param time double to set mTimeTillFire to
	 */
	void SetTimeTillFire(double time) { mTimeTillFire = time; }

	/** Setter function for mTile member
	* \param open shared pointer to set mTile to
	*/
	void SetTile(CItemOpen* open) { mTile = open; }

	/** Getter function for mGrabbed member
	* \return Boolean of mGrabbed
	*/
	bool Grabbed() const { return mGrabbed; }

	/** Setter function for mGrabbed member
	* \param grabbed Boolean to set mGrabbed to
	*/
	void SetGrabbed(bool grabbed) { mGrabbed = grabbed; }

	/** Getter function for mTile member
	* \return shared pointer to mTile
	*/
	CItemOpen* GetTile() const { return mTile; }

	/** Abstract method to initialize weapon
	*/
	virtual void InitializeWeapon() = 0;

	/** Abstract method add weapon to game
	*/
	virtual void AddWeapon() = 0;


private:

	double mTimeTillFire = 5;		///< Time in seconds until next firing

	bool mFire = false;			///< Boolean represents whether or not currently firing

	CItemOpen* mTile = nullptr;			///< Tile this tower sits on

	bool mGrabbed = false;			///< Whether or not tower is grabbed
};

