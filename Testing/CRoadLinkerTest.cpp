#include "pch.h"
#include "CppUnitTest.h"
#include "RoadLinker.h"
#include "Game.h"
#include "ItemRoad.h"
#include "ItemHouse.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{

	TEST_CLASS(CRoadLinkerTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(CollectedRoads)
		{
			CGame game;
			// add 10 roads and 10 houses to the game
			for (int i = 0; i < 10; ++i)
			{
				game.Add(make_shared<CItemRoad>(&game));
				game.Add(make_shared<CItemHouse>(&game));
			}

			CRoadLinker linker;
			game.Accept(&linker);

			vector<CItemRoad*> roads = linker.GetRoads();

			Assert::AreEqual(roads.size(), 10, .00001);
		}
		
		TEST_METHOD(LinkedRoads)
		{
			CGame game;
			
			// add 3 roads to the game at (32, 32), (32, 96), (96, 96)
			
			auto road1 = make_shared < CItemRoad>(&game);
			road1->SetLocation(32, 32);
			game.Add(road1);

			auto road2 = make_shared < CItemRoad>(&game);
			road2->SetLocation(32, 96);
			game.Add(road2);

			auto road3 = make_shared < CItemRoad>(&game);
			road3->SetLocation(96, 96);
			game.Add(road3);

			CRoadLinker linker;
			game.Accept(&linker);

			// link the roads
			linker.LinkRoads();

			
			// road2 neighbors road1 to the south  
			Assert::IsTrue(road1->GetNeighbor(L"S") != nullptr);

			// road1 neighbors road2 to the north
			Assert::IsTrue(road2->GetNeighbor(L"N") != nullptr);

			// road2 neighbors road3 to the West
			Assert::IsTrue(road3->GetNeighbor(L"W") != nullptr);

			// road3 neighbors road 2 to the east
			Assert::IsTrue(road2->GetNeighbor(L"E") != nullptr);
			
			
			// make sure that all other pointers are nullptr
			// road1 nullptrs
			Assert::IsTrue((road1->GetNeighbor(L"N") == nullptr));
			Assert::IsTrue((road1->GetNeighbor(L"E") == nullptr));
			Assert::IsTrue((road1->GetNeighbor(L"W") == nullptr));
			// road2 nullptrs
			Assert::IsTrue((road2->GetNeighbor(L"S") == nullptr));
			Assert::IsTrue((road2->GetNeighbor(L"W") == nullptr));
			// road3 nullptrs
			Assert::IsTrue((road3->GetNeighbor(L"N") == nullptr));
			Assert::IsTrue((road3->GetNeighbor(L"E") == nullptr));
			Assert::IsTrue((road3->GetNeighbor(L"S") == nullptr));
		}


	};
}