#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "ItemRoad.h"
#include "BalloonRed.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CBalloonTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestUpdateRoad)
		{
			CGame game;
			
			// make 2 roads
			auto road1 = make_shared<CItemRoad>(&game);
			auto road2 = make_shared<CItemRoad>(&game);
			// make them both EW roads;
			road1->SetRoadDirection(L"EW");
			road2->SetRoadDirection(L"EW");
			// locate them next to each other
			road1->SetLocation(32, 32);
			road2->SetLocation(96, 32);
			// make them neighbors
			road2->SetNeighbor(&(*road1));
			road1->SetNeighbor(&(*road2));

			// make sure they are neighbors
			Assert::IsTrue(road2->GetNeighbor(L"W") == &(*road1));
			Assert::IsTrue(road1->GetNeighbor(L"E") == &(*road2));

			// create 2 balloons
			auto balloon1 = make_shared<CBalloonRed>(&game, &(*road1), L"E");
			balloon1->SetLocation(63, 32);
			balloon1->SetSpeed(1);

			auto balloon2 = make_shared<CBalloonRed>(&game, &(*road2), L"W");
			balloon2->SetLocation(65, 32);
			balloon2->SetSpeed(1);

			// add the items to the game

			game.Add(road1);
			game.Add(balloon1);
			game.Add(balloon2);
			game.Add(road2);

			// start the game
			game.SetButtonPressed(true);

			// balloon1 should be on road 1 (nothing has changed)
			Assert::IsTrue(balloon1->GetRoad() == &(*road1));

			// balloon2 should be on road 2 (nothing has changed)
			Assert::IsTrue(balloon2->GetRoad() == &(*road2));

			//update the game by 1 second
			game.Update(1);

			//balloon1 should still be on road1
			Assert::IsTrue(balloon1->GetRoad() == &(*road1));

			//balloon2 should still be on road2
			Assert::IsTrue(balloon2->GetRoad() == &(*road2));

			// update the game by 1 second
			game.Update(1);

			// ballon1 should now be on road 2
			Assert::IsTrue(balloon1->GetRoad() == &(*road2));

			// ballon2 should now be on road 1
			Assert::IsTrue(balloon2->GetRoad() == &(*road1));
		}
		TEST_METHOD(TestUpdateHeading)
		{
			CGame game;
			// make a road
			auto road1 = make_shared<CItemRoad>(&game);

			// make it a NW road
			road1->SetRoadDirection(L"NW");

			// set its location
			road1->SetLocation(32, 32);

			// make a ballon heading in the east direction
			auto balloon1 = make_shared<CBalloonRed>(&game, &(*road1), L"E");
			balloon1->SetLocation(31, 32);
			balloon1->SetSpeed(1);

			// add the items to the game
			game.Add(road1);
			game.Add(balloon1);

			// set the game to start
			game.SetButtonPressed(true);

			// update the game
			game.Update(1);

			// balloon should now be heading north
			Assert::IsTrue(balloon1->GetHeading() == L"N");

			game.Update(1);
			Assert::IsTrue(balloon1->GetY() == 31);
			game.Update(1);
			Assert::IsTrue(balloon1->GetY() == 30);

		}
	};
}