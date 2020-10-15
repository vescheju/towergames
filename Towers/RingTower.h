#pragma once
#include "Tower.h"
class CRingTower :
	public CTower
{
public:
	/// constructor
	CRingTower(CGame* game);

	/// Default constructor (disabled)
	CRingTower() = delete;

	/// Copy constructor (disabled)
	CRingTower(const CRingTower&) = delete;


private:

};

