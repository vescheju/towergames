#include "pch.h"
#include "TowerEight.h"
#include "Dart.h"
#include "Game.h"
#include <string>

/// towerEight filename
const std::wstring TowerEightName = L"images/tower8.png";

double TimeBetweenShots = 5;

const std::vector<int> DegreesVector{ 0, 45, 90, 135, 180, 225, 270, 315 };

/**
* TowerEight Constructor
* \param game the whole game
*/
CTowerEight::CTowerEight(CGame* game) :
	CTower(game)
{
	SetImage(TowerEightName);
	for (int angle : DegreesVector)
	{
		std::shared_ptr<CDart> dart(new CDart(game, angle));
		mDarts.push_back(dart);
		game->Add(dart);
	}
	
}



void CTowerEight::Fire()
{
	for (auto dart : mDarts)
	{
		dart->Fire();
	}
}



void CTowerEight::Update(double elapsed)
{
	mTimeTillFire -= elapsed;
	if (mTimeTillFire <= 0)
	{
		mTimeTillFire += TimeBetweenShots;
		Fire();
	}
}

void CTowerEight::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	for (auto dart : mDarts)
	{
		dart->SetLocation(x, y);
	}
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CTowerEight::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/