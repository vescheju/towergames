#include "pch.h"
#include "TileLocker.h"
#include "ItemOpen.h"

const double LockThreshold = 60;

void CTileLocker::VisitOpen(CItemOpen* open)
{
	mOpenTiles.push_back(open);
}


CItemOpen* CTileLocker::LockTower(std::shared_ptr<CItem> tower)
{
	double grabbedX = tower->GetX();
	double grabbedY = tower->GetY();
	for (auto tile : mOpenTiles)
	{
		if (tile->GetTower() == nullptr)
		{
			double tileX = tile->GetX();
			double tileY = tile->GetY();

			double distance = sqrt((grabbedX - tileX) * (grabbedX - tileX)
				+ (grabbedY - tileY) * (grabbedY - tileY));

			if (distance < LockThreshold)
			{
				tile->SetTower(tower);
				tower->SetLocation(tileX, tileY);
				return tile;
			}
		}
	}
	return nullptr;
}