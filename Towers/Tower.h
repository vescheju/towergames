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


private:

	double mTimeTillFire = 5;		///< Time in seconds until next firing

	bool mFire = false;			///< Boolean represents whether or not currently firing
};

