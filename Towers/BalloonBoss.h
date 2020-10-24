/**
 * \file BalloonBoss.h
 *
 * \author Ian Masterson
 *
 * Class represents the bass balloon
 */

#pragma once
#include "Balloon.h"
#include "ItemFog.h"


/**
 * boss balloon class
 */
class CBalloonBoss :
    public CBalloon
{
public:
    CBalloonBoss(CGame* game, CItemRoad* road, std::wstring heading);

	/// Default constructor (disabled)
	CBalloonBoss() = delete;

	/// Copy consturctor (disbabled)
	CBalloonBoss(const CBalloonBoss&) = delete;

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBalloonBoss(this); }

	virtual void Update(double elapsed) override;

	virtual void AddActiveWeapon(CWeapon* weapon) override;

	virtual void RemoveActiveWeapon(CWeapon* weapon) override;

	void InitializeCariers();

	void Pop();

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* getter for the fog
	* 
	* \return the fog in the balloon
	*/
	std::shared_ptr<CItemFog> GetFog() { return mFog; }

private:
	/// the balloons to drop when it pops
	std::vector<std::shared_ptr<CBalloonRed> > mBalloons;

	/// the number of balloons the boss holds
	int mNumBalloons = 4;

	/// pointer to the fog that follows the boss
	std::shared_ptr<CItemFog> mFog;
};

