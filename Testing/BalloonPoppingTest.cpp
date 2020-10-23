#include "pch.h"
#include "CppUnitTest.h"
#include "ItemRoad.h"
#include "BalloonRed.h"
#include "Game.h"
#include "ItemRemover.h"
#include "Dart.h"
#include "DamageVisitor.h"
#include "ItemRoad.h"
#include "Item.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(BalloonPoppingTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		

		TEST_METHOD(BalloonPopTest)
		{
			// create the game
			CGame game;

			// make 2 balloons and a dart
			// make 2 balloons
			auto balloon1 = make_shared<CBalloonRed>(&game, nullptr, L"");
			auto balloon2 = make_shared<CBalloonRed>(&game, nullptr, L"");

			auto dart = make_shared<CDart>(&game, 0);
			// make a road
			auto road = make_shared<CItemRoad>(&game);
			// set the images
			wstring filename1 = L"images/red-balloon.png";
			auto  mItemImage1 = shared_ptr<Bitmap>(Bitmap::FromFile(filename1.c_str()));

			wstring filename2 = L"images/dart.png";
			auto  mItemImage2 = shared_ptr<Bitmap>(Bitmap::FromFile(filename2.c_str()));

			balloon1->SetImagePtr(mItemImage1);
			balloon2->SetImagePtr(mItemImage2);
			balloon1->SetRoad(&(*road));
			balloon2->SetRoad(&(*road));
			// set the images so that they are not touching
			// (32, 32)(96, 32)
			balloon1->SetLocation(32, 32);
			balloon2->SetLocation(96, 32);

			dart->SetLocation(32, 32);

			game.Add(balloon1);
			game.Add(balloon2);
			game.Add(dart);

			// create the visitor
			CDamageVisitor damager;
			game.Accept(&damager);

			// deal the damage
			damager.DealDamage();

			// make sure that balloon1 hp went down, but balloon2s stayed the same
			Assert::IsTrue(balloon1->GetHealth() == 0);
			Assert::IsTrue(balloon2->GetHealth() == 1);

			//remove the poped balloon from the game

			CItemRemover remover;
			game.Accept(&remover);

			vector<CItem*> itemsToRemove = remover.GetRemovedItems();

			// assert that there are 3 items in the game
			Assert::IsTrue(game.GetItemNumber() == 3);

			game.Remove(itemsToRemove);

			// assert that there are now only 2 items in the list
			Assert::IsTrue(game.GetItemNumber() == 2);
		}

	};
}