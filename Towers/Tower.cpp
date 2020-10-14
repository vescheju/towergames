#include "pch.h"
#include "Tower.h"
#include <string>

class CGame;

CTower::CTower(CGame* game, const std::wstring& filename) : CItem(game, filename)
{

}