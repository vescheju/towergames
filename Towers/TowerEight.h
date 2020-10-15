#pragma once
#include "Tower.h"
class CTowerEight :
	public CTower
{
public:
	/// constructor
	CTowerEight(CGame* game);

	/// Default constructor (disabled)
	CTowerEight() = delete;

	/// Copy constructor (disabled)
	CTowerEight(const CTowerEight&) = delete;

private:

};

