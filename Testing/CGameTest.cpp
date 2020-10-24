#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "ItemHouse.h"
#include "ItemTree.h"
#include "BombTower.h"
#include "RingTower.h"
#include "TowerEight.h"
#include "GrabVisitor.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const wstring HouseImage = L"images/house1.png";
const wstring TreeImage = L"images/trees1.png";


namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			g_dir[999] = L'\0';
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestConstructor)
		{
			CGame game;
		}
		TEST_METHOD(TestCGameHitTest)
		{
		
			CGame game;
			
			// Test Hit Test of an empty Game

			Assert::IsTrue(game.HitTest(100, 200) == nullptr,
				L"Testing empty game");


			// Test Hit Test with bombs added
			shared_ptr<CBombTower> bomb = make_shared<CBombTower>(&game);
			bomb->SetLocation(200, 200);
			game.Add(bomb);

			shared_ptr<CRingTower> tower = make_shared<CRingTower>(&game);
			tower->SetLocation(100, 350);
			game.Add(tower);

			Assert::IsTrue(game.HitTest(200, 200) == bomb, L"Testing bomb");

			Assert::IsTrue(game.HitTest(100, 350) == tower, L"Testing ring tower");

			Assert::IsTrue(game.HitTest(110, 360) == tower, L"Testing ring tower");


			// Test Hit Test with items in it, make sure doesn't return tiles
			shared_ptr<CItemHouse> house = make_shared<CItemHouse>(&game);
			house->SetImage(HouseImage);
			house->SetLocation(5, 5);
			game.Add(house);

			shared_ptr<CItemTree> tree = make_shared<CItemTree>(&game);
			tree->SetImage(HouseImage);
			tree->SetLocation(100, 100);
			game.Add(tree);

			Assert::IsTrue(game.HitTest(5, 5) == nullptr, L"Testing house");

			Assert::IsTrue(game.HitTest(100, 100) == nullptr, L"Testing tree");

			Assert::IsTrue(game.HitTest(110, 110) == nullptr, L"Testing tree");

			// Test an empty spot with all added

			Assert::IsTrue(game.HitTest(300, 300) == nullptr, L"Testing empty spot");

		}
		TEST_METHOD(TestCGameIterator)
		{
			// Construct a game object
			CGame game;

			// Add some tiles
			auto tile1 = make_shared<CItemHouse>(&game);
			auto tile2 = make_shared<CItemHouse>(&game);
			auto tile3 = make_shared<CItemHouse>(&game);

			game.Add(tile1);
			game.Add(tile2);
			game.Add(tile3);

			// Begin points to the first item
			auto iter1 = game.begin();

			// End points after the last item
			auto iter2 = game.end();

			Assert::IsTrue(tile1 == *iter1, L"First item correct");
			++iter1;
			Assert::IsTrue(tile2 == *iter1, L"Second item correct");
			++iter1;
			Assert::IsTrue(tile3 == *iter1, L"Third item correct");
			++iter1;
			Assert::IsFalse(iter1 != iter2);

		}

	};
}