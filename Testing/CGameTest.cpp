#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "ItemHouse.h"
#include "ItemTree.h"
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

			// Test Hit Test with items in it
			shared_ptr<CItemHouse> house = make_shared<CItemHouse>(&game);
			house->SetImage(HouseImage);
			house->SetLocation(5, 5);
			game.Add(house);

			shared_ptr<CItemTree> tree = make_shared<CItemTree>(&game);
			tree->SetImage(HouseImage);
			tree->SetLocation(100, 100);
			game.Add(tree);

			Assert::IsTrue(game.HitTest(5, 5) == house, L"Testing house");

			Assert::IsTrue(game.HitTest(100, 100) == tree, L"Testing tree");

			// Test an empty spot with both added

			Assert::IsTrue(game.HitTest(300, 300) == nullptr, L"Testing empty spot");

		}
		TEST_METHOD(TestCGameIterator)
		{


		}

	};
}