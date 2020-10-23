/**
 * \file BalloonBoss.h
 *
 * \author Ian Masterson
 *
 * Class represents the bass balloon
 */

#pragma once
#include "Balloon.h"


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

private:
	/// the balloons to drop when it pops
	std::vector<std::shared_ptr<CBalloonRed> > mBalloons;

	/// the number of balloons the boss holds
	int mNumBalloons = 4;
};

