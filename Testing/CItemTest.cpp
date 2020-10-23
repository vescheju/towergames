#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{

	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		/** Constructor
		 * \param aquarium The aquarium this is a member of */
		CItemMock(CGame* game) :
			CItem(game)
		{
			SetImagePtr(mGame->GetImage(L"red-balloon.png"));
		}

		/** Accept a visitor
		* a dummy function to make sure the class is not abstract
		* \param visitor The visitor we accept 
		*/
		virtual void Accept(CItemVisitor* visitor) override {}

	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemConstruct)
		{
			CGame game;
			CItemMock item(&game);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CGame game;
			CItemMock item(&game);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemHitTest)
		{
			// Create an item to test
			CGame game;
			CItemMock item(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			item.SetLocation(100, 200);

			// Center of the item should be a true
			Assert::IsTrue(item.HitTest(100, 200));

			// Left of the item
			Assert::IsFalse(item.HitTest(10, 200));

			// Right of the item
			Assert::IsFalse(item.HitTest(200, 200));

			// Above the item
			Assert::IsFalse(item.HitTest(100, 0));

			// Below the item
			Assert::IsFalse(item.HitTest(100, 300));

			// Of item transparent pixel
			Assert::IsFalse(item.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}
	};
}