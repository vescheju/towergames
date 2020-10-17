#include "pch.h"
#include "CppUnitTest.h"

#include "XmlLoader.h"
#include "Game.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CXmlLoadingTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestLoaderConstruct)
		{
			CGame game;
			CXmlLoader xmlLoader(&game);
		}

		TEST_METHOD(TestLevelInfo)
		{
			CGame game;
			CXmlLoader xmlLoader(&game);
			xmlLoader.Load(L"level1.xml");

			// test that the level starts are equal
			Assert::AreEqual(game.GetStartX(), 0);
			Assert::AreEqual(game.GetStartY(), 13);

			// test that the height and width are equal
			Assert::AreEqual(game.GetLevelWidth(), 16);
			Assert::AreEqual(game.GetLevelHeight(), 16);
		}

		TEST_METHOD(TestItemDeclaration)
		{
			CGame game;
			CXmlLoader xmlLoader(&game);
			xmlLoader.Load(L"level1.xml");
			
			// check to see if the loader got every declaration
			Assert::AreEqual(xmlLoader.GetDeclarationSize(), 19);
		}

		TEST_METHOD(TestItemInit)
		{
			CGame game;
			CXmlLoader xmlLoader(&game);
			xmlLoader.Load(L"level1.xml");

			// check to see the loader got every init
			Assert::AreEqual(static_cast<int>(xmlLoader.GetItems().size()), 256);
		}

		TEST_METHOD(TestValidItemInit)
		{
			CGame game;
			CXmlLoader xmlLoader(&game);
			xmlLoader.Load(L"level1.xml");

			std::vector<std::shared_ptr<CItem> > items = xmlLoader.GetItems();

			// check that an item location is saved properly
			// the first item has a location of 0, 15 which when converted to 
			// its true location is 32, 992
			Assert::AreEqual(items[0]->GetX(), 32, 0.00001);
			Assert::AreEqual(items[0]->GetY(), 992, 0.00001);

		}

	};
}